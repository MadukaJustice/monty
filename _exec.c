#include "monty.h"

int exec_help
(char *opcode, instruction_t opcodes[], char *opstr,
unsigned int line_no, unsigned int it);


/**
 * f_exec - executes stack operations
 * @opcodes: arrays of opcodes intructions
 * @len: opcodes length
 * @fd: a file descriptor
 * @lineptr: a pointer to char, to store lines of text
 */
void f_exec(instruction_t opcodes[], unsigned int len, int fd, char *lineptr)
{
	unsigned int offset, line_no, i;
	char *opcode, *opstr;
	int nread, test;

	offset = 0;
	line_no = 1;
	opstr = NULL;
	do {
		nread = getline(&lineptr, fd, &offset);
		if (nread == -1 || nread == 0)
			break;
		get_optstr(&opstr, lineptr);
		opcode = strtok(opstr, " ");
		if (opcode == NULL)
		{
			++line_no;
			free(opstr);
			continue;
		}
		i = 0;
		while (i < len)
		{
			test = exec_help(opcode, opcodes, opstr, line_no, i);
			if (test == 1)
				break;
			++i;
		}
		if (i == len)
		{
			printf("L<%u>: unknow instruction <%s>\n", line_no, opcode);
			free(opstr);
			exit(EXIT_FAILURE);
		}
		++line_no;
	} while (nread != -1);
	free(opstr);
}


/**
 * exec_help - to reduce the number of lines of exec
 * Also, within here the execution of the opcodes is done
 * @opcode: the opcode
 * @opcodes: the array of instructions
 * @opstr: the pointer that contains the instructions
 * It is freed here
 * @line_no: the current line number
 * @it: the counter from the external loop in exec,
 * Used to access the instructions array
 * Return: an integer of a match is made or not
 * The integer is used to break out of the external loop
 */
int exec_help(char *opcode, instruction_t opcodes[], char *opstr,
unsigned int line_no, unsigned int it)
{
	char *val;

	if (strcmp(opcode, opcodes[it].opcode) == 0)
	{
		if (strcmp(opcode, "push") == 0)
		{
			val = strtok(NULL, "");
			if (val == NULL)
			{
				printf("L<%u>: usage: push integer\n", line_no);
				free(opstr);
				exit(EXIT_FAILURE);
			}
			opcodes[it].f(&stack, atoi(val));
			return (1);
		}
		opcodes[it].f(&stack, line_no);
		return (1);
	}
	return (-1);
}
