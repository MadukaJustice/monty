#include "monty.h"

/**
 * pint - print value at top of stack
 * @stack: pointer to top of stack
 * @ln: line number
 */
void pint(stack_t **stack, unsigned int ln)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
