#include <stdlib.h>
#include <stdio.h>
/**
 * read_line - reads a line and then prints it.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(void)
{
	char *buffer;
	size_t buffer_size = 1024;
	size_t characters;

	buffer = (char *)malloc(buffer_size * sizeof(char));
	if (!buffer)
	{
		perror("Coulnd't allocate memory!");
		return (1);
	}
	printf("$ ");
	characters = getline(&buffer, &buffer_size, stdin);
	printf("%s\n", buffer);
	return (0);
}
