#include <stdlib.h>
#include <stdio.h>
/**
 * main - Entry point
 * @argc: argument counter.
 * @argv: argument vector.
 *
 * Return: 1 on success, -1 on failure.
 */
int main(int argc, char **argv)
{
	int i = 0;

	while (argv[i])
		printf("%s\n", argv[i++]);
	return (1);
}
