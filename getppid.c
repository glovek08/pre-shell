#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 * main - Entry point for function that prints the PID and PPID of the current program.
 *
 *
 * Return: 1 on success, 0 on failure.
 */
int main(void)
{
	printf("%i\n", getpid());
	printf("%i\n", getppid());
	return(1);
}
