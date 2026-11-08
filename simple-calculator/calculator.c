#include <stdio.h>

/**
 * print_menu - prints the calculator menu and the choice prompt
 */
void print_menu(void)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
	printf("Choice: ");
}

/**
 * read_operands - prompts for and reads two integers
 * @a: where to store the first number
 * @b: where to store the second number
 *
 * Return: 1 if both numbers were read, 0 otherwise
 */
int read_operands(int *a, int *b)
{
	printf("A: ");
	if (scanf("%d", a) != 1)
		return (0);
	printf("B: ");
	if (scanf("%d", b) != 1)
		return (0);
	return (1);
}

/**
 * main - entry point of the simple calculator
 *
 * Return: 0 on success
 */
int main(void)
{
	int choice, a, b;

	printf("Simple Calculator\n");
	while (1)
	{
		print_menu();
		if (scanf("%d", &choice) != 1)
		{
			printf("\nBye!\n");
			return (0);
		}
		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}
		if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}
		if (!read_operands(&a, &b))
		{
			printf("\nBye!\n");
			return (0);
		}
		if (choice == 1)
			printf("Result: %d\n", a + b);
		else if (choice == 2)
			printf("Result: %d\n", a - b);
		else
			printf("Not implemented yet\n");
	}
	return (0);
}
