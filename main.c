#include "monty.h"
#include <sys/stat.h>
#include <fcntl.h>
#define OPS 7 /*length of the opcodes*/

stack_t *stack = NULL;
unsigned int stack_size = 0;

/**
 * main - run program
 * @ac: argument count
 * @argv: argument variables
 * Return: 0
 */
int main(int ac, char *argv[])
{
	int fd;
	char *lineptr, *opstr, *opcode, *val;
	int nread;
	unsigned int offset, line_no, i;
	instruction_t opcodes[OPS];

	offset = 0;
	line_no = 1;
	if (ac == 1)
	{
		printf("%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	load_opcodes(opcodes, OPS);

	lineptr = opstr = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	do {
		nread = getline(&lineptr, fd, &offset);
		if (nread == -1 || nread == 0)
			break;
		get_optstr(&opstr, lineptr);
		opcode = strtok(opstr, " ");
		if (opcode == NULL)
		{
			++line_no;
			continue;
		}
		i = 0;
		while (i < OPS)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				if (strcmp(opcode, "push") == 0)
				{
					val = strtok(NULL, " ");
					if (val == NULL)
					{
						printf("L<%u>: usage: push integer\n", line_no);
						free(opstr);
						exit(EXIT_FAILURE);
					}
					opcodes[i].f(&stack, atoi(val));
					break;
				}
				opcodes[i].f(&stack, line_no);
				break;
			}
			++i;	
		}
		if (i == OPS)
		{
			printf("L<%u>: unknow instruction <%s>\n", line_no, opcode);
			free(opstr);
			exit(EXIT_FAILURE);
		}
		++line_no;
	} while (nread != -1);

	close(fd);
	free(opstr);
	return (0);
}
