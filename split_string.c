#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * split_string - receives a string and splits it in two.
 * @buffer: pointer to the target string.
 * @delim: the specified delimiter.
 * @first_half: pointer to store the first token.
 * @second_half: pointer to store the second token.
 *
 * Return: 0 on success, 1 on failure.
 */
int split_string(char *buffer, const char *delim, char **first_half, char **second_half)
{
	*first_half = strtok(buffer, delim);
	if (*first_half == NULL)
		return (1);
	*second_half = strtok(NULL, delim);
	if (*second_half == NULL)
		return (1);
	return (0);
}
/**
 * main - Entry point.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(void)
{
	char *buffer = NULL;
	char *delim = NULL;
	size_t delim_size = 0;
	size_t buffer_size = 0;
	ssize_t input_length;
	char *first = NULL, *second = NULL;

	printf("Input delimiter: ");
	ssize_t delim_len = getline(&delim, &delim_size, stdin);
	if (delim_len == -1)
	{
		perror("Delimiter set failed");
		free(delim);
		return (EXIT_FAILURE);
	}
	if (delim[delim_len - 1] == '\n')
		delim[delim_len - 1] = '\0';

	printf("Input text to split: ");
	input_length = getline(&buffer, &buffer_size, stdin);
	if (input_length == -1)
	{
		perror("getline failed");
		free(buffer);
		return (EXIT_FAILURE);
	}
	if (buffer[input_length - 1] == '\n')
		buffer[input_length - 1] = '\0';
	if (split_string(buffer, delim, &first, &second) == 0)
	{
		printf("First part: %s\n", first);
		printf("Second part: %s\n", second);
	}
	else
		printf("Failed to split input.\n");
	free(buffer);
	free(delim);
	return (0);
}
