#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of the stack;
 * @ln: line number
 */
void pop(stack_t **stack, unsigned int ln)
{
	stack_t *node;

	node = *stack;
	if (node == NULL)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	*stack = node->prev;
	if (*stack != NULL)
		(*stack)->next = NULL;
	free(node);
}
