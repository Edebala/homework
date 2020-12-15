#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "matrixio.h"
#include "compare.h"
#include "lab11hw.h"
#include "lab12hw.h"

int main()
{
	srand(time(0));
	int **a, n = 6;
	a = createParking(&n);
	showParking(n,a);
	for(int i=0;i<n;i++)
		free(a[i]);
	free(a);
	return 0;
}
