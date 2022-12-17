#include "monty.h"

/**
 * swap - swaps the top to elements of stack
 * @stack: pointer to top of stack
 * @ln: line number
 */
void swap(stack_t **stack, unsigned int ln)
{
	int tmp;
	stack_t *node;
	unsigned int stack_size;

	stack_size = 0;
	node = *stack;
	while (node != NULL)
	{
		++stack_size;
		node = node->prev;
	}
	
	if (stack_size < 2)
	{
		printf("L<%d>: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = tmp;
}
