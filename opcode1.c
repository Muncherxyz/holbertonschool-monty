#include "monty.h"

/**
 * swap_monty_stack - swaps top two nodes of stack
 * @stack: stack
 * @line_number: line number from inbound file
 * Return: void
 */
void swap_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeHold;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_sg(stack);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_sg(stack);
		exit(EXIT_FAILURE);
	}
	nodeHold = (*stack)->next;
	(*stack)->next = nodeHold->next;
	(*stack)->prev = nodeHold;
	nodeHold->next = (*stack);
	nodeHold->prev = NULL;
	(*stack) = nodeHold;
}

/**
 * add_monty_stack - adds top 2 nodes of stack
 * @stack: stack
 * @line_number: line number from inbound file
 * Return: void
 */
void add_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeHold;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	nodeHold = (*stack);
	nodeHold->next->n = (((*stack)->n) + ((*stack)->next->n));
	(*stack) = nodeHold->next;
	free(nodeHold);
}
