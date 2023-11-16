#include "monty.h"
/**
 * mod - computes the remainder division of the second top by the top
 * @stack: double pointer to the top of the stack
 * @line_number: number of the line where the opcode was found
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = second->n % first->n;

	second->n = result;
	free(first);
	*stack = second;
}
