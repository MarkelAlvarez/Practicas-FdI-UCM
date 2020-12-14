#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <getopt.h>
#include <string.h>

// Maximum number of characters in the full path of the filenames
#define MAX_CAMINO 4096
// Size of each class in the histogram of filesizes
#define C10KB 10240

/*
 * The program generates a histogram of the directories inside a
 * hierarchy depending on the total quantity of files included in this hierarchy
 * (option -n) or a histogram counting all the sizes inside the same hierarchy (option -t)
 */
 
char *diract = ".";	// If the name of the directory is not provided
					// the program uses the current directory

int totalf;			// Total number of files
int totald;			// Total number of directories
int tam[11], num[11]; 	// Two histograms, one for the option -t, the other one for the option -n


int optiont=0, optionn=0;

// This function traverses the hierarchy of directories starting with
// directory 'dir' and applying the function f update the histogram
int traverse_tree(char *dir, int (*f)()) {
	DIR *dirp;
	struct dirent *dp;
	struct stat buf;
	char filename[256];
	int ok;

	// Opens the directory 'dir', obtaining the descriptor dirp of type DIR
	if ((dirp = opendir(dir)) == NULL) { perror(dir); return -1; }

	// Applies the accounting function 'f' to directory 'dir'
	if (f(dir) == -1){
		closedir(dirp);
		return -1;
	}
	
	// Traverse the set of directories under the current one
	
	
	// Start reading an entry in the current directory
	while ((dp = readdir(dirp)) != NULL) {
		//	Avoid entries "." and ".." that would produce an 
		//	infinite loop if they were considered
		if (!strcmp(".", dp->d_name)) continue;
		if (!strcmp("..", dp->d_name)) continue;
		// Build the name of the file starting with the current directory 'dir'
		if(snprintf(filename, 256, "%s/%s", dir, dp->d_name)>=256){
			fprintf(stderr, "Name too long!!\n");
			closedir(dirp);
			return -1;
        }
		// Try to figure out if the entry corresponds to a sub-directory
		ok = lstat(filename, &buf);
		// If it is a subdir, apply this function and
		//	update the total number of directories traversed
		if ((ok != 1) && ((buf.st_mode & S_IFMT)==S_IFDIR))  {
			totald++;
			if (traverse_tree(filename, f) == -1) break;
		}
	}
        closedir(dirp);
	return 0;
}

/* Function that builds the histogram of files according to file sizes
 * It examines all the files in the current directory 'dir', 
 * 	check their sizes and according to this value increment
 *	the corresponding class accumulator.
 * This function also updates the counter with the total number of files
 */
int cnt_tam(char *dir) {
	DIR *dirp;
	struct dirent *dp;
	struct stat buf;
	char filename[256];
	int n, ok;

	if ((dirp = opendir(dir)) == NULL) { perror(dir); return -1; }

	while ((dp = readdir(dirp)) != NULL) {
		if (!strcmp(".", dp->d_name)) continue;
		if (!strcmp("..", dp->d_name)) continue;

		if(snprintf(filename, 256, "%s/%s", dir, dp->d_name)>=256){
			fprintf(stderr, "Name too long!!\n");
			closedir(dirp);
			return -1;
        }
		ok = lstat(filename, &buf);
		if ((ok != 1) && ((buf.st_mode & S_IFMT)==S_IFREG)) {
			totalf++;
			if ((n = buf.st_size / C10KB) < 0)
				continue;
			else if (n < 10)
				tam[n]++;
			else
				tam[10]++;
		}
	}
        closedir(dirp);
	return 0;
}

/* Function that builds the histogram of directories according to the number of
 * files each directory contain.
 * It counts the number of files contained in the directory 'dir', 
 * 	and depending on the obtained value increments the corresponding class accumulator. 
 */
int cnt_num(char *dir) {
	DIR *dirp;
	struct dirent *dp;
	int n, nf=0;

	if ((dirp = opendir(dir)) == NULL) { perror(dir); return -1; }
	while ((dp = readdir(dirp)) != NULL) {
		if (!strcmp(".", dp->d_name)) continue;
		if (!strcmp("..", dp->d_name)) continue;
		nf++;
	}
	if ((n = (nf/10)) < 10)
		num[n]++;
	else
		num[10]++;
        closedir(dirp);
	return 0;
}

/* Function that presents on screen the whole histogram
 * either the histogram of files according their size (option -t)
 * or the histogram of directories according their number of files (option -n)
 */

void print_report(char *dir) {
	int i;

	printf("Results for the directory %s.\n", dir);
	if (optiont) {
		printf("Range\t\tTotal\tPercentage\n");
		for (i=0; i<10; i++) 
			printf("[%dK, %dK]\t%d\t%f%%\n",
				10*i, 10*i+10, tam[i], (tam[i]*100.0)/totalf);
		printf("Greater\t\t%d\t%f%%\n", tam[10], (tam[10]*100.0)/totalf);
		printf("=======\t\t=====\t=======\n");
		printf("TOTAL FILES\t%d\t%f%%\n\n", totalf, 100.00);
	}
	if (optionn) {
		printf("Range\t\tTotal\tPercentage\n");
		for (i=0; i<10; i++) 
			printf("[%2d, %3d]\t%d\t%f%%\n",
				10*i, 10*i+10, num[i], (num[i]*100.0)/totald);
		printf("More than 100\t%d\t%f%%\n", num[10], (num[10]*100.0)/totald);
		printf("=======\t\t=====\t=======\n");
		printf("TOTAL DIRECT.\t%d\t%f%%\n\n", totald, 100.00);
	}
}

int main(int argc, char *argv[]) {
	char *dir;
	char option;
	int first;

	// Examine the options in the command line
	while ((option = getopt(argc, argv, "tn")) != EOF)  {
		switch (option)  {
		case 't':		// Histogram of files by size
			optiont = 1; break;
		case 'n': 		// Histogram of directories by number of files
			optionn = 1; break;
		default:
			fprintf(stderr, "Error, illegal option: %c\n", option);
		}
	}
	// By default the -t option is applied
	if (!optiont && !optionn) optiont=1;
	
	first=1;
	for (; (optind<argc)||first ; optind++) {
		first = 0;
		dir = (optind < argc) ? argv[optind] : diract;

		if (optiont) {
			totalf = 0; totald = 1;
			// Traverse the tree of directories executing the function cnt_tam
			traverse_tree(dir, cnt_tam);
		}
		if (optionn) {
			totald = 1;
			// Traverse the tree of directories executing the function cnt_num
			traverse_tree(dir, cnt_num);
		}
		print_report(dir);
		//printf("%d: directory %s [%d,%d]\n", optind, dir, optiont, optionn);
	}

	return 0;
}
