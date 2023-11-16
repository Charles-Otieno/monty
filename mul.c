#include "monty.h"
/**
 * mul - multiplies the second top by first top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: number of the line where the opcode was found
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	result = second->n * first->n;

	second->n = result;
	free(first);
	*stack = second;
}
