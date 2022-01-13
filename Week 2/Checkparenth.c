//Program to check the parenthesis

#include <stdio.h>
#include <string.h>
#define MAX 80

int a = -1;
char stack[MAX];

void push(char s)
{
	stack[++a] = s;
}

char pop()
{
	return stack[a--];
}

int main(){

	char strin[MAX];
	char ch = '\0';
	int k = 1, j = 0;

	printf("\nEnter the [] or {} or () as string:- ");
	scanf("%s", strin);

	while (strin[j] != '\0')
	{
		if (strin[j] == '(' || strin[j] == '{' || strin[j] == '[')
			push(strin[j]);

		if (strin[j] == ')' || strin[j] == '}' || strin[j] == ']')
		{
			if (a == -1)
				k = 0;
			else
			{
				ch = pop();
				if (strin[j] == ')' && ch != '(')
					k = 0;

				if (strin[j] == '}' && ch != '{')
					k = 0;

				if (strin[j] == ']' && ch != '[')
					k = 0;
			}
		}
		j++;
	}
	if (a >= 0)
		k = 0;
	if (k == 1)
		printf("\nTRUE");
	else
		printf("\nFALSE");

	return 0;
}
