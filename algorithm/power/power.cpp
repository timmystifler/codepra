#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

bool check_valid(double base, int exp);
double power(double base, int exponent);
double power_with_unsignedexp(double base, unsigned int exp);
bool invalid_input = false;

double power(double base, int exponent)
{
	invalid_input = check_valid(base, exponent);
	if(invalid_input)
	{
		return 0.0;
	}

	unsigned int abs_exponent = (unsigned int)exponent;
	if(exponent < 0)
		abs_exponent = (unsigned int)(-exponent);

	double result = power_with_unsignedexp(base, abs_exponent);
	
	if(exponent < 0)
		return 1.0 / result;
	else
		return result;
}

double power_with_unsignedexp(double base, unsigned int exp)
{
	int i = 0;
	double result = 1.0;
	for(i = 0; i < exp; i++)
		result *= base;
	return result;
}

bool check_valid(double base, int exp)
{
	if((base - 0.0 < 0.0000001) && (base - 0.0 > -0.0000001) 
			&& (exp < 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}



int main()
{
	double base = 3.0;
	int exp = -1;
	scanf("%lf %d", &base, &exp);
	double result = power(base, exp);
	if(!invalid_input)
	{
		printf("%lf\n", result);
	}
}
