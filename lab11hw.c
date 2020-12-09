#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include "lab11hw.h"
#include "compare.h"
#include "matrixio.h"

int max(int a,int b)
{
		return (a>b)?a:b;
}

void divisible(char* input)
{
	int n,sum = 0,product = 1,*a;
	float average = 0;
	a = readIntArray(input,&n);
	for(int i=0;i<n;i++){
		if(a[i]%2==0)sum += a[i];
		if(a[i]%3==0)product *= a[i];
		if(a[i]%5==0)average += a[i];
	}
	average /= n;
	printf("%i %f %i\n",sum, average, product);	
}

void first(char *source,int type)
{
	int size,n;
	void *data,*input;
	int (*compare)(const void*,const void*);
	void (*print)(int,const void*,char*);
	
	switch(type)
	{
		case CHAR:{
			data = readCharArray(source,&n);
			input = malloc(sizeof(char));
			scanf("%c", input);
			compare = charCompare;
			print = printCharArray;
			size = sizeof(char);
			break;
		}
		case INT:{
			data = readIntArray(source,&n);
			input = malloc(sizeof(int));
			scanf("%i",input);
			compare = intCompare;
			print = printIntArray;
			size = sizeof(int);
			break;
		}
		case FLOAT:{
			data = readFloatArray(source,&n);
			input = malloc(sizeof(float));
			scanf("%i",input);
			compare = floatCompare;
			print = printFloatArray;
			size = sizeof(float);
			break;
		}
		case STRING:{
			char buffer[32];
			compare = stringCompare;
			print = printStringArray;
			data = readStringArray(source,&n);
			print(n,data,0);
			scanf("%s", buffer);
			input = malloc(strlen(buffer)*sizeof(char));
			strcpy(input,buffer);
			size = sizeof(char*);
			break;
		}
	}
	print(n,data,0);
	qsort(data,n,size,compare);
	print(n,data,0);
	if(bsearch(input,data,n,size,compare)){
	printf("A beirt valami resze a tombnek\n");
	}
	else{
		printf("A beirt valami nem eleme a tombnek\n");
	}
	free(data);
	free(input);
}

void second(int n,int m)
{
	int **a =generateIntArrayTwo(n,m);
	unsigned **prt = parity(n,m,a);
	unsigned *rowPrt = rowParity(n,m,a);
	printUnsignedArrayTwo(n,m,(const void**)prt,0);
	printUnsignedArray(n,(const void*)rowPrt,0);
	for(int i=0;i<n;i++)
			free(a[i]);
	free(a);
	for(int i=0;i<n;i++)
			free(prt[i]);
	free(prt);
	free(rowPrt);
}

void third(int n,int m)
{
	int **a = generateIntArrayTwo(n,m);
	printIntArrayTwoHex(n,m,(const void**)a,0);
	int x=0,y=0,mx=INT_MAX;
	while(1)
	{
			printf("%x ", a[x][y]);
			mx = 0;
		if(x>0)
			mx = max(a[x-1][y],mx); 
		if(x<n-1)
			mx = max(a[x+1][y],mx); 
		if(y>0)
			mx = max(a[x][y-1],mx); 
		if(y<m-1)
			mx = max(a[x][y+1],mx); 
		if(a[x][y] >= mx)break;
		if(x>0   && a[x-1][y] == mx)x--;
		if(y<m-1 && a[x][y+1] == mx)y++;
		if(x<n-1 && a[x+1][y] == mx)x++;
		if(y>0   && a[x][y-1] == mx)y--;
	}
	for(int i=0;i<n;i++)
		free(a[i]);
	free(a);
}
