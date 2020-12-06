#include <stdlib.h>
#include <stdio.h>
#include "matrixio.h"

int main()
{
	int n,m, **a;
	a = readArrayTwo("in.txt",&n,&m);
	printTwo(n,m,a,0);
	printSpiral(n,m,a);
	return 0;
}
