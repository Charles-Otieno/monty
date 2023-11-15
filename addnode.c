#include "monty.h"
/**
 * add_node - Adds a new node to the stack
 * @stack: A pointer to the head of the stack
 * @n: The value to be stored in the new node
 *
 * Return: Void
 */
void add_node(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
