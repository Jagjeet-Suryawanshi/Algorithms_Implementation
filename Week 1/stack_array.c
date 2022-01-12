#include <stdio.h>
#include <conio.h>
#define CAPACITY 5

void push(int);
int pop();
void traverse();
int isFull();
int isEmpty();
int element;
void exit();
int stack[CAPACITY];
int top = -1;

void main(void)
{
	int cho, item;
	while (1)
	{
		printf("1. push \n");
		printf("2. pop \n");
		printf("3. traverse \n");
		printf("4. exit \n");
		printf("Enter your choices :");
		scanf("%d", &cho);

		switch (cho)
		{
		case 1:
			printf("\nEnter the item ");
			scanf("%d", &item);
			push(item);
			break;
		case 2:
			item = pop();
			if (element == 0)
			{
				printf("stack is underflow");
			}
			else
			{
				printf(" popped item is %d", element);
			}
			break;
		case 3:
			traverse();
			break;
		case 4:
			exit(0);
		default:
			printf("Invalid input \n");
		}
	}
}

void push(int element)
{
	if (isFull())
	{
		printf("stack is overflow \n");
	}
	else
	{
		top++;
		stack[top] = element;
		printf("%d is pushed \n", element);
	}
}
int isFull()
{
	if (top == CAPACITY - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pop()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		return stack[top--];
	}
}
int isEmpty()
{
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void traverse()
{
	if (isEmpty())
	{
		printf("Stack is empty \n");
	}
	else
	{
		int i;
		printf("Stack elements : \n");
		for (i = 0; i <= top; i++)
		{
			printf("%d \n", stack[i]);
		}
	}
}
