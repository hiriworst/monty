#include "monty.h"

/**
 * m_pstr - prints the string starting at the top of the stack + '\n'
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *adc = *stack;
	char str[1028];
	size_t i = 0;
	(void)line_number;

	if (!adc)
	{
		printf("\n");
		return;
	}
	for (; adc->next; adc = adc->next)
		;
	for (; adc && adc->n; adc = adc->prev, i++)
	{
		if (adc->n <= 0 || adc->n > 126)
			break;
		str[i] = adc->n;
	}
	str[i] = '\0';
	printf("%s\n", str);
}

/**
 * isint - checks if s could be converted to an decimal int
 * @s: sourcer string
 * Return: 0 on success, otherwise 1
 */
int isint(char *s)
{
	size_t i;

	if (!s)
		return (1);
	for (i = 0; s[i]; i++)
	{
		if ((s[i] < 48 || s[i] > 57) && (s[i] != '-'))
			return (1);
	}
	return (0);
}
/**
 * m_rotl - rotates the stack to the top
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void m_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *adc = *stack;
	(void)line_number;

	if (!(*stack) || !((*stack)->next))
		return;
	for (; adc->next; adc = adc->next)
		;
	adc->prev->next = NULL;
	adc->prev = NULL;
	adc->next = *stack;
	(*stack)->prev = adc;
	*stack = adc;
}
/**
 * m_rotr - rotates the stack to the bottom
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void m_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *adc = *stack;
	(void)line_number;

	if (!(*stack) || !((*stack)->next))
		return;
	for (; adc->next; adc = adc->next)
		;
	adc->next = *stack;
	(*stack)->prev = adc;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	adc->next->next = NULL;
}
/**
 * m_queue - changes structure to queue mode
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void m_queue(stack_t **stack, unsigned int line_number)
{
	cmds *adc = head;
	(void)stack;
	(void)line_number;

	if (!adc->mode)
	{
		for (; adc; adc = adc->next)
			adc->mode = 1;
	}
}
