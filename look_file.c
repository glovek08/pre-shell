#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Looks for files in the current PATH.
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	char *path, *token, full_path[1024];
	int i;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	path = getenv("PATH");
	if (!path)
	{
		fprintf(stderr, "PATH environment variable not set\n");
		return (1);
	}

	for (i = 1; i < argc; i++)
	{
		char *path_copy = strdup(path);

		if (!path_copy)
		{
			perror("strdup");
			return (1);
		}

		token = strtok(path_copy, ":");
		while (token)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", token, argv[i]);
			if (access(full_path, X_OK) == 0)
			{
				printf("%s\n", full_path);
				break;
			}
			token = strtok(NULL, ":");
		}

		if (!token)
			printf("%s not found\n", argv[i]);

		free(path_copy);
	}

	return (0);
}
