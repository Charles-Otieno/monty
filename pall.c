#include "monty.h"

/**
 * pall - Prints all elements in the stack
 * @stack: A pointer to the head of the stack
 * @line_number: The line number of the opcode in the Monty file
 *
 * Return: Void
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
