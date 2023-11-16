#include "monty.h"
#define UNUSED(x) (void)(x)

/**
 * push - Adds a new node to the stack
 * @stack: A pointer to the head of the stack
 * @line_number: The line number of the opcode in the Monty file
 * @n: The value to be stored in the new node
 *
 * Return: Void
 */
void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new_node;

	UNUSED(line_number);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		data.r_flag = 0;
		return;
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
