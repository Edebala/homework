#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrixio.h"

float* readFloatArray(char* in,int *n){
	FILE *fi = fopen(in,"r");
	if(fi == 0){
		printf("Error\n");	
		return 0;
	}
	fscanf(fi,"%i",n);
	float *a = (float*) malloc((*n) *sizeof(float));
	for(int i=0;i<*n;i++)
		fscanf(fi,"%f ",&a[i]);
	return a;
}

int* readIntArray(char* in,int *n){
	FILE *fi = fopen(in,"r");
	if(fi == 0){
		printf("Error\n");	
		return 0;
	}
	fscanf(fi,"%i",n);
	int *a = (int*) malloc((*n) *sizeof(int));
	for(int i=0;i<*n;i++)
		fscanf(fi,"%i ",&a[i]);
	return a;
}

char* readCharArray(char* in,int *n){
	FILE *fi = fopen(in,"r");
	if(fi == 0){
		printf("Error\n");	
		return 0;
	}
	fscanf(fi,"%i",n);
	char *a = (char*) malloc((*n) *sizeof(char));
	for(int i=0;i<*n;i++)
		fscanf(fi,"%c ",&a[i]);
	return a;
}

char** readStringArray(char* in,int *n){
	FILE *fi = fopen(in,"r");
	if(fi == 0){
		printf("Error\n");	
		return 0;
	}
	char buffer[32];
	fscanf(fi,"%i",n);
	char **a = (char**) malloc((*n) *sizeof(char*));
	for(int i=0;i<*n;i++){
		fscanf(fi,"%s ",buffer);
		a[i] = (char*) malloc((strlen(buffer)) * sizeof(char));
		strcpy(a[i],buffer);
	}
	return a;
}

int** readArrayTwo(char* in,int *n,int *m){
	FILE *fi = fopen(in,"r");
	if(fi == 0){
		printf("Error\n");	
		return 0;
	}
	fscanf(fi,"%i",n);
	fscanf(fi,"%i",m);
	int **a = (int**) malloc((*n) *sizeof(int*));
	for(int i=0;i<*n;i++){
		a[i] = (int*) malloc((*m) * sizeof(int));
		for(int j=0;j<*m;j++){
			fscanf(fi,"%i ",&a[i][j]);
		}
	}
	return a;
}

int** generateIntArrayTwo(int n, int m)
{
	int **a = (int**) malloc((n) *sizeof(int*));
	for(int i=0;i<n;i++){
		a[i] = (int*) malloc((m) * sizeof(int));
		for(int j=0;j<m;j++){
			a[i][j] = rand();
		}
	}
	return a;
}

void printStringArray(int n,const void *a, char* out){
	if(a == 0){
		printf("Empty\n");
		return;	
	}
	if(out == 0){
		for(int i=0;i<n;i++)
			printf("%s ",((char**)a)[i]);
		printf("\n");
	}
	else{
		FILE *fo = fopen(out,"w");
		for(int i=0;i<n;i++)
			fprintf(fo,"%s ",((char**)a)[i]);
		fclose(fo);
	}
}

void printCharArray(int n,const void *a, char* out){
	if(a == 0){
		printf("Empty\n");
		return;	
	}

	if(out == 0){
		for(int i=0;i<n;i++)
			printf("%c ",((char*)a)[i]);
		printf("\n");
	}
	else{
		FILE *fo = fopen(out,"w");
		for(int i=0;i<n;i++)
			fprintf(fo,"%c ",((char*)a)[i]);
		fclose(fo);
	}
}

void printIntArrayHex(int n,const void *a, char* out){
	if(a == 0){
		printf("Empty\n");
		return;	
	}

	if(out == 0){
		for(int i=0;i<n;i++)
			printf("%6.0x ",((unsigned*)a)[i]);
		printf("\n");
	}
	else{
		FILE *fo = fopen(out,"w");
		for(int i=0;i<n;i++)
			fprintf(fo,"%6.0x ",((unsigned*)a)[i]);
		fclose(fo);
	}
}

void printIntArray(int n,const void *a, char* out){
	if(a == 0){
		printf("Empty\n");
		return;	
	}

	if(out == 0){
		for(int i=0;i<n;i++)
			printf("%6.0i ",((unsigned*)a)[i]);
		printf("\n");
	}
	else{
		FILE *fo = fopen(out,"w");
		for(int i=0;i<n;i++)
			fprintf(fo,"%6.0i ",((unsigned*)a)[i]);
		fclose(fo);
	}
}

void printUnsignedArray(int n,const void *a, char* out){
	if(a == 0){
		printf("Empty\n");
		return;	
	}

	if(out == 0){
		for(int i=0;i<n;i++)
			printf("%u ",((int*)a)[i]);
		printf("\n");
	}
	else{
		FILE *fo = fopen(out,"w");
		for(int i=0;i<n;i++)
			fprintf(fo,"%u ",((int*)a)[i]);
		fclose(fo);
	}
}

void printFloatArray(int n,const void *a, char* out){
	if(a == 0){
		printf("Empty\n");
		return;	
	}

	if(out == 0){
		for(int i=0;i<n;i++)
			printf("%f ",((float*)a)[i]);
		printf("\n");
	}
	else{
		FILE *fo = fopen(out,"w");
		for(int i=0;i<n;i++)
			fprintf(fo,"%0.2f ",((float*)a)[i]);

		fclose(fo);
	}
}

void printUnsignedArrayTwo(int n, int m,const void **a,char* out){
	if(a == 0){
		printf("Empty\n");
		return;	
	}

	if(out == 0){
		for(int i=0;i<n;i++)
			printUnsignedArray(m,a[i],0);
		printf("\n");
	}
	else{
		FILE *fo = fopen(out,"w");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				fprintf(fo,"%u ",((unsigned **)a)[i][j]);
			fprintf(fo,"\n");
		}
		fclose(fo);
	}
}

void printIntArrayTwoHex(int n, int m,const void **a,char* out){
	if(a == 0){
		printf("Empty\n");
		return;	
	}

	if(out == 0){
		for(int i=0;i<n;i++)
			printIntArrayHex(m,(void*)a[i],0);
		printf("\n");
	}
	else{
		FILE *fo = fopen(out,"w");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				fprintf(fo,"%x ",((int **)a)[i][j]);
			fprintf(fo,"\n");
		}
		fclose(fo);
	}
}

void printIntArrayTwo(int n, int m,const void **a,char* out){
	if(a == 0){
		printf("Empty\n");
		return;	
	}

	if(out == 0){
		for(int i=0;i<n;i++)
			printIntArray(m,(void*)a[i],0);
		printf("\n");
	}
	else{
		FILE *fo = fopen(out,"w");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				fprintf(fo,"%i ",((int **)a)[i][j]);
			fprintf(fo,"\n");
		}
		fclose(fo);
	}
}

void printSpiral(int n,int m,int **a)
{
	int direction = 0,sn=0,sm=0,i=-1,j=0;
	while((n > sn) && (m > sm))
	{
		switch(direction%4)
		{
			case 0:
			{
				i++;
				if(i == n-1)
				{
					direction ++;
					sm++;
				}
			}break;

			case 1:
			{
				j++;
				if(j == m-1)
				{
					direction ++;
					n--;
				}
			}break;
			case 2:
			{
				i--;
				if(i == sn)
				{
					direction ++;
					m--;
				}
			}break;

			case 3:
			{
				j--;
				if(j == sm)
				{
					direction ++;
					sn++;
				}
			}break;
		}
		printf("%i ",a[i][j]);
	}
	putchar('\n');
}
	
unsigned** parity(int n,int m,int **a)
{
	int tmp;
	unsigned **prt = (unsigned**) malloc(n*sizeof(unsigned*));
	for(int i=0;i<n;i++){
		prt[i] = (int*) calloc(m, sizeof(int));
		for(int j=0;j<m;j++){
				tmp = a[i][j];
			while(tmp !=0){
				prt[i][j] += tmp%2;
				tmp/=2;
			}
		}
	}
	return prt;
}

unsigned* rowParity(int n,int m,int **a)
{
	int tmp;
	unsigned *prt = (unsigned*) calloc(n,sizeof(unsigned));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
				tmp = a[i][j];
			while(tmp !=0){
				prt[i] += tmp%2;
				tmp/=2;
			}
		}
	}
	return prt;
}
