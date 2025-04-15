#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 *
 *
 *
 */

int main(void) 
{
	pid_t ppid;
	ppid = getppid();
	printf("%d\n", ppid);
	printf("%d\n", getpid());
	return(EXIT_SUCCESS);
}
