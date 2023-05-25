#include "monty.h"

/**
 * m_stack - changes structure to stack
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void m_stack(stack_t **stack, unsigned int line_number)
{
	cmds *adc = head;
	(void)stack;
	(void)line_number;

	if (adc->mode)
	{
		for (; adc; adc = adc->next)
			adc->mode = 0;
	}
}

/**
 * m_pushq - push on queue mode
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void m_pushq(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		freell(stack);
		exit(EXIT_FAILURE);
	}
	if (isint(head->cmd[1]))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		freell(stack);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(head->cmd[1]);
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
