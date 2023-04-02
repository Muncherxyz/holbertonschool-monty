#include "monty.h"

/**
 * op_fun_res - matches inbound opcode to supported
 * @lineCount: line from inbound file where opcode appears
 * @dasStack: head of stack
 * @bop: opcode argument
 * Return: void
 */
void op_fun_res(unsigned int lineCount, char *bop, stack_t **dasStack)
{
	unsigned int j;
	instruction_t betty[] = {{"pall", pall_monty_stack},
	{"push", push_monty_stack}, {"pint", pint_monty_stack},
	{"nop", nop_monty_stack}, {"pop", pop_monty_stack},
	{"swap", swap_monty_stack}, {"add", add_monty_stack}};

	for (j = 0; j < 7; j++)
	{
		if (strcmp(betty[j].opcode, bop) == 0)
		{
			betty[j].f(dasStack, lineCount);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lineCount, bop);
	free_sg(dasStack);
	exit(EXIT_FAILURE);
}
