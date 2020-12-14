#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char buffer[BUFSIZ];			// Transfer buffer
int size;						// Number of bytes used by the buffer

int main(int argc, char *argv[]) {
	int fd_source, fd_dest;		// File descriptors
	int nbytes;

	// The number of arguments in the command line is correct?
	if ((argc < 3) || (argc > 4))  {
		fprintf(stderr, "Usage: %s source destination [BLOCK_SIZE]\n", argv[0]);
		exit(-1);
	}

	// Selection of the block size, as the transfer unit
	size = (argc == 4) ? atoi(argv[3]) : sizeof(buffer);
	// Test: the block size cannot be neither negative
	//		nor greater than the maximum value reserved for 'buffer'
	if ((size <= 0) || (size > sizeof(buffer)))
		fprintf(stderr, "%s must be between 1 and %ld\n", argv[3], (long int)sizeof(buffer)), exit(-1);

	// Opening fd_source, read only
	if (!strcmp(argv[1], "-"))	// If the first argument is '-', use STDIN
		fd_source = STDIN_FILENO;
	else if ((fd_source = open(argv[1], O_RDONLY)) == -1)
		perror("open source"), exit(-1);

	// Opening the destination file, write only.
	//		If it already exists, it's truncated; if not, it created with permissions rw-rw-rw-
	if (!strcmp(argv[2], "-"))	// If the second argument is "-", STDOUT is used
		fd_dest = STDOUT_FILENO;
	else if ((fd_dest = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
		perror("open destination"), exit(-1);

	printf("Starting COPY\n");
	// command is: read 'size' bytes; it actually reads 'nbytes'
	while ((nbytes = read(fd_source, buffer, size)) > 0)
		// it commands writing 'nbytes'; all of them should be written
		if (write(fd_dest, buffer, nbytes) < 0)
			perror("write destination"), exit(-1);
	printf("Ends of COPY\n");

	// If the number of read bytes is 0, it means END OF FILE
	if (nbytes != 0) perror("read source"), exit(-1);

	// Close all the open files.
	//	Since we are at the end of the program it is not strictly needed.
	//		The exit() function close them anyway.
	close(fd_source);
	close(fd_dest);

	exit(0);
}
