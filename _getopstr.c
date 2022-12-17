#include "monty.h"

/**
 * get_optstr - gets the opcode string from a line
 * @optstr: a pointer to a pointer to char
 * @line: a line of text
 */
void get_optstr(char **optstr, char *line)
{
	unsigned int i, j, count, space_count;

	i = 0;
	count = 0;
	space_count = 0;
	if (*optstr != NULL)
		free(*optstr);
	while (line[i] == ' ' || line[i] == '\t')
		++i;
	while (line[i] != '\0')
	{
		++count;
		if (line[i] == ' ')
			++space_count;
		if (space_count == 2)
			break;
		++i;
	}
	*optstr = malloc(sizeof(char) * (count + 1));
	if (*optstr == NULL)
	{
		free(line);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	i = 0;
	space_count = 0;
	while (*(line + i) == ' ' || *(line + i) == '\t')
		++i;
	j = 0;
	while (j < count)
	{
		(*optstr)[j] = line[i];
		if (line[i] == ' ')
			++space_count;
		++i, ++j;
	}
	free(line);
	(*optstr)[j] = '\0';
}
