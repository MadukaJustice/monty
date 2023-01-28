#include "monty.h"
#define BUFSIZE 1024


/**
 * _getline - gets a line of text from a buffer
 * @lineptr: a pointer to a pointer to char
 * @fd: the file to getline from
 * @offset: pointer to file offset
 * Return: number of chars read, otherwise -1
 */
int _getline(char **lineptr, int fd, unsigned int *offset)
{
	char buf[BUFSIZE];
	int nread;
	unsigned int i;

	lseek(fd, *offset, SEEK_SET);
	nread = read(fd, buf, BUFSIZE);
	if (nread <= 0)
		return (nread);
	i = 0;
	while (buf[i] != '\n')
		++i;
	++i;
	*offset += i;
	*lineptr = malloc(sizeof(char) * (i + 1));
	if (*lineptr == NULL)
	{
		fprintf(stderr, "%s\n", "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (nread > 0 && ((*lineptr)[i] = buf[i]) != '\n')
		++i;
	(*lineptr)[i] = '\0';

	return (nread);
}
