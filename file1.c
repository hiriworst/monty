#include "monty.h"

/**
 * mega_pint - Add a new node at the end of a list
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void mega_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *adc = *stack;

	if (!adc)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	for (; adc->next; adc = adc->next)
		;
	printf("%d\n", adc->n);

}

/**
 * m_pop - Function that removes the top element of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *adc = *stack, *adc2 = NULL;

	if (!adc)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	for (; adc && adc->next; adc = adc->next)
		;
	adc2 = adc;
	adc->prev->next = NULL;
	free(adc2);
}

/**
 * m_swap - Function that swaps the top two elements of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *adc = *stack;
	size_t i = 1;

	for (; adc && adc->next; adc = adc->next, i++)
		;
	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	if (i == 2)
	{
		(*stack)->prev = adc;
		adc->next = (*stack);
		(*stack)->next = NULL;
		*stack = adc;
		(*stack)->prev = NULL;
		return;
	}
	adc->prev = adc->prev->prev;
	adc->prev->next->next = NULL;
	adc->next = adc->prev->next;
	adc->prev->next->prev = adc;
	adc->prev->next = adc;
}

/**
 * m_add - Function that adds the top two elements of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_add(stack_t **stack, unsigned int line_number)
{
	stack_t *adc = *stack;
	size_t i = 1;

	for (; adc && adc->next; adc = adc->next, i++)
		;
	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	adc->prev->n += adc->n;
	m_pop(stack, line_number);
}

/**
 * m_nop - Function that doesn't do anything
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
