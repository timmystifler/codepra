#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

void print_max_digits(int n);
void print_max_digits_recursively(char *number, int length, int index);
void print_nums(char *number);
void print_max_digits_recursively(char *number, int length, int index);

void print_max_digits(int n)
{
	if(n <= 0)
	{
		return ;
	}
	char *num = new char[n+1];
	num[n] = '\0';

	for(int i = 0; i < 10; i++)
	{
		num[0] = i + '0';
		print_max_digits_recursively(num, n, 0);
	}
	delete [] num;
}

void print_max_digits_recursively(char *number, int length, int index)
{
	if(index == length-1)
	{
		print_nums(number);
		return ;
	}
	for(int i = 0; i < 10; i++)
	{
		number[index+1] = i + '0';
		print_max_digits_recursively(number, length, index+1);
	}
}


void print_nums(char *number)
{
	bool is_begin_zero = true;

	for(int i = 0; i < strlen(number); i++)
	{
		if(is_begin_zero && number[i]!= '0')
		{
			is_begin_zero = false;
			printf("%s\n", number+i);
			break;
		}
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	print_max_digits(n);
}
