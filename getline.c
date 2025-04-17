#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

ssize_t _getline(char **, size_t *, FILE *);

/**
 * main - Entry point.
 *
 * Return: 0 On success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	char *buffer;
	size_t buffer_size = 1024;
	size_t characters;

	buffer = (char *)malloc(sizeof(char) * buffer_size);
	if (!buffer)
	{
		free(buffer);
		perror("Couldn't allocate memory!");
		return (EXIT_FAILURE);
	}
	printf("$ ");
	characters = _getline(&buffer, &buffer_size, stdin);
	printf("%s\n", buffer);
	free(buffer);
	return (EXIT_SUCCESS);
}
/**
 * _getline - reads an entire line from the stream.
 * @lineptr: pointer to the buffer that contains the text.
 * @n: pointer to the size of the buffer.
 * @stream: file stream to read from.
 *
 * Return: number of characters read, -1 on failure.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer;
	size_t size;
	int c;
	size_t i = 0;

	if (!lineptr || !n || !stream)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		size = 128;
		*lineptr = malloc(size * sizeof(char));
		if (*lineptr == NULL)
			return (-1);
		*n = size;
	}
	else
		size = *n;
	buffer = *lineptr;
	while ((c = getc(stream)) != EOF)
	{
		if (i >= size - 1)
		{
			size *= 2;
			buffer = realloc(buffer, size * sizeof(char));
			if (buffer == NULL)
				return (-1);
			*lineptr = buffer;
			*n = size;
		}
		buffer[i++] = c;
		if (c == '\n')
			break;
	}
	if (c == EOF && i == 0)
		return (-1);
	buffer[i] = '\0';
	return (i);
}
