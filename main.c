#include "monty.h"
#include <sys/stat.h>
#include <fcntl.h>
#define OPS 7 /*length of the opcodes*/

stack_t *stack = NULL;

/**
 * main - run program
 * @ac: argument count
 * @argv: argument variables
 * Return: 0
 */
int main(int ac, char *argv[])
{
	int fd;
	char *lineptr;
	instruction_t opcodes[OPS];

	if (ac == 1)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	load_opcodes(opcodes, OPS);

	lineptr = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	f_exec(opcodes, OPS, fd, lineptr);
	close(fd);
	return (0);
}
