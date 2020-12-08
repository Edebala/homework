#include <stdlib.h>
#include <stdio.h>
#include "lab11hw.h"
#include "compare.h"
#include "matrixio.h"

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
			data = readStringArray(source,&n);
			input = malloc(sizeof(char*));
			scanf("%s", ((char*)input));
			compare = stringCompare;
			print = printStringArray;
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
		printf("A beirt valami nem resze a tombnek\n");
	}
	free(data);
}
