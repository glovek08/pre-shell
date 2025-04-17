#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t pid = 0;

	printf("Example text, before fork.\nPID: %i\n", pid);
	pid = fork();
	if (pid == -1)
	{
		perror("Failed to fork.\n");
		return (1);
	}

	printf("Example text, after fork.\nPID: %i\n", pid);
	
	return (0);
}
