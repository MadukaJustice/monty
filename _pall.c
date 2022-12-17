#include "monty.h"

/**
 * pall - prints all the values on the stack, from the top
 * @stack: pointer to top of stack
 * @ln: line number
 */
void pall(stack_t **stack, unsigned int ln)
{
	stack_t *node;

	(void) ln;
	node = *stack;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->prev;
	}
}
