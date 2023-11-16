#include "monty.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]);
gvab_t data;

/**
 * main - Main function
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	int n = 0;
	FILE *file;
	char line[1024];
	char *opcode;
	char *arg;

	data.r_flag = 1;

	/* Check if correct number of arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* Open the file and handle errors */
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file\n");
		return (EXIT_FAILURE);
	}

	/* Read the file line by line and process each line */
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		/* Split the line into opcode and argument */
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (opcode == NULL)
			continue;

		/* Process the opcode */
		if (strcmp(opcode, "push") == 0)
		{
			n = atoi(arg);
			push(&stack, line_number, n);
			if (data.r_flag == 0)
			{
				fclose(file);
				return (EXIT_FAILURE);
			}

		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, line_number);
		}
		else if (strcmp(opcode, "sub") == 0)
		{
			sub(&stack, line_number);
		}
		else if (strcmp(opcode, "div") == 0)
		{
			div_stack(&stack, line_number);
		}
		else if (strcmp(opcode, "mul") == 0)
		{
			mul(&stack, line_number);
		}
		else if (strcmp(opcode, "mod") == 0)
		{
			mod(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			return (EXIT_FAILURE);
		}
	}

	fclose(file);
	free_stack(&stack);

	return (EXIT_SUCCESS);
}
