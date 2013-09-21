#include "commonlib.h"
#include <stdio.h>
#include <stdlib.h>


struct struct2d
{
	double a[2];
	char b[2];
};

struct struct12c
{
	char b[12];
};

int main()
{
	MEASURE_C(int, "int cost");
	MEASURE_C(char*, "char* cost");
	MEASURE_C(double, "double");
	MEASURE_C(struct struct2d, "struct2d");
	MEASURE_C(struct struct12c, "struct12c");

}
