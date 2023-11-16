#include "monty.h"

/**
 * pall - Prints all elements of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: The line number of the opcode in the Monty file
 *
 * Return: Void
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
