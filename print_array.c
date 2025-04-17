#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 *
 *
 *
 *
 *
 */

char **str_split(char *str, int *num_words) 
{
	char *piece, **str_arr = NULL, *str_cpy = NULL;
	int i = 0;

	if (str == NULL)
		return (NULL);

	*num_words = 0;

	str_cpy = strdup(str);
	if (!str_cpy)
		return (NULL);

	piece = strtok(str_cpy, " ");
	while (piece != NULL)
	{
		if ((*piece) != '\n')
			(*num_words)++;
		piece = strtok(NULL, " ");
	}
	free(str_cpy);

	str_arr = malloc(sizeof(char *) * (*num_words));
	if (!str_arr)
		return (NULL);

	piece = strtok(str, " ");
	for (i = 0; piece != NULL;)
	{
		if ((*piece) != '\n')
		{
			str_arr[i] = malloc(strlen(piece) + 1);
			if (!str_arr[i])
				return (NULL);
			strcpy(str_arr[i], piece);
			i++;
		}
		piece = strtok(NULL, " ");
	}
	return (str_arr);
}

int main(void)
{
	int nwords = 0;
	char str[] = "Hewwo World";
	char **arr = str_split(str, &nwords);

	for (int i = 0; i < nwords; i++)
	{
		printf("word %d: %s\n", i, arr[i]);
		free(arr[i]);
	}
	free(arr);

	return (0);
}
