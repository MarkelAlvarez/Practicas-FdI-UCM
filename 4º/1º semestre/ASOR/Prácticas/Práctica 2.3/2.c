// Write a program that shows the planification policy (as a string) and the priority of the processes.
// of the current process as well as the maximum and minimum priority of the planification
// policy.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sched.h>
#include <sys/resource.h>

int main()
{
	char *policy_name;
	struct sched_param p;
	int policy, min_priority, max_priority;
	
	sched_getparam(0, &p);

	policy = sched_getscheduler(getpid());
	min_priority = sched_get_priority_min(policy);
	max_priority = sched_get_priority_max(policy);
	
	switch (policy)
	{
		case SCHED_FIFO:
			policy_name = "FIFO";
			break;
		case SCHED_RR:
			policy_name = "RR";
			break;
		case SCHED_OTHER:
			policy_name = "OTHER";
			break;
		default:
			policy_name = "UNKNOWN";
			break;
	}
	
	printf("Planification policy: %s\n", policy_name);
	printf("Current priority: %d\n", p.sched_priority);
	printf("Maximum priority: %d\n", max_priority);
	printf("Minimum priority: %d\n", min_priority);
	
	return 0;
}