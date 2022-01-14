#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/utsname.h>

int main()
{
	struct utsname sysinfo;

	if (uname(&sysinfo) == -1)
	{
		printf("Error %d: %s\n", errno, strerror(errno));
	}
	else
	{
		printf("System name: %s\n", sysinfo.sysname);
		printf("Machine name: %s\n", sysinfo.nodename);
		printf("Release: %s\n", sysinfo.release);
		printf("Version: %s\n", sysinfo.version);
		printf("Machine identifier: %s\n", sysinfo.machine);
	}
	
	return 0;
}