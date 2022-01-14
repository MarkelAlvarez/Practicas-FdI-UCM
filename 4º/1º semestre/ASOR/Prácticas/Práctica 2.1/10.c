#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
	printf("User UID: %d\n", getuid());
	printf("User EUID: %d\n", geteuid());

    struct passwd *user = getpwuid(getuid());
	printf("User name: %s\n", user->pw_name);
	printf("User directory: %s\n", user->pw_dir);
	printf("User description: %s\n", user->pw_gecos);
	
	return 0;
}