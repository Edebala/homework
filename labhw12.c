#include <stdio.h>
#include "lab12hw.h"
#include "matrixio.h"

int ** createParking(int *n)
{
	scanf("%i",n);
	int **a = generateIntArrayTwo(*n,*n);
	for(int i=0;i<(*n)*(*n);i++)
	{
		if(a[i/(*n)][i%(*n)]<10) a[i/(*n)][i%(*n)] = 0;
	}
	return a;
}

int countCars(int n,int **a)
{
	int counter = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>=30)counter++;
			if(a[i][j]!=0 && a[i][j]<30)counter--;
		}
	return counter;
}

float average(int n,int **a)
{
	float sum = 0, nr = 0;
	for(int i=0;i<n;i++)
	{
		sum += a[i][i];
		nr += a[i][i]!= 0;
	}
	sum/=nr;
	return sum;
}

int showParking(int n,int **a)
{
	for(int i=0;i<n;i++)
	{
		if(i%2 == 1)
		{
			printf("|  ");
			for(int j=0;j<n;j++)
				printf("   ");
			printf("|\n");
		}
		else
		{
			printf("|  ");
			for(int j=0;j<n;j++)
				printf("+--");
			printf("+\n");
		}
		printf("|  ");
		for(int j=0;j<n;j++)
		{
			if(a[i][j]!= 0)
			printf("|%2i",a[i][j]);
			else printf("|  ");
		}
		printf("|");
		printf("\n");
	}
			printf("|  ");
			if(n%2)
			{
			for(int j=0;j<n;j++)
				printf("   ");
			printf("|\n|  ");
			}
			for(int j=0;j<n;j++)
					printf("+--");
		printf("+\n");
		int c = countCars(n,a);
		printf("There is %s number of cars with number smaller than 30 %s cars with a greater than 30\n"
				,c>0?"a lower":c==0?"the same":"a greater",c==0?"as":",than");
		printf("The Average of the IDNumber of Cars on the first diagonal is %2.2f\n",average(n,a));
}
