#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: number of the line where the opcode was found
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	sum = first->n + second->n;

	second->n = sum;
	free(first);
	*stack = second;
}
