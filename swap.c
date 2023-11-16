#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: number of the line where the opcode was found
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
  stack_t *first;
  stack_t *second;
  int temp;

  if (*stack == NULL || (*stack)->next == NULL)
  {
      fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
      exit(EXIT_FAILURE);
  }

  first = *stack;
  second = (*stack)->next;

  temp = first->n;
  first->n = second->n;
  second->n = temp;
}
