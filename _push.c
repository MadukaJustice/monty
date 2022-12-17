#include "monty.h"

/**
 * push - push value to top of stack
 * @stack: pointer to top of stack
 * @val: value to push to stack
 */
void push(stack_t **stack, unsigned int val)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("%s\n", "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	node->n = val;
	node->prev = *stack;
	node->next = NULL;
	if (*stack != NULL)
		(*stack)->next = node;
	*stack = node;
}
