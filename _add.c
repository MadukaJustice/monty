#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of stack
 * @ln: line number
 */
void add(stack_t **stack, unsigned int ln)
{
	stack_t *node;
	int sum;

	if (stack_size < 2)
	{
		printf("L<%d>: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	sum = 0;
	node = *stack;
	sum += node->n;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	sum += (*stack)->n;
	(*stack)->n = sum;
	--stack_size;
	free(node);
}
