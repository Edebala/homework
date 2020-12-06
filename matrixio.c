#include <stdio.h>
#include <stdlib.h>

int* readArray(char* in,int *n){
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

void print(int n,int *a, char* out){
	if(a == 0){
		printf("Empty\n");
		return;	
	}

	if(out == 0){
		for(int i=0;i<n;i++)
			printf("%i\t",a[i]);
		printf("\n");
	}
	else{
		FILE *fo = fopen(out,"w");
		for(int i=0;i<n;i++)
			fprintf(fo,"%i\t",a[i]);
		fclose(fo);
	}
}

void printTwo(int n, int m,int **a,char* out){
	if(a == 0){
		printf("Empty\n");
		return;	
	}

	if(out == 0){
		for(int i=0;i<n;i++)
			print(m,a[i],0);
		printf("\n");
	}
	else{
		FILE *fo = fopen(out,"w");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				fprintf(fo,"%i ",a[i][j]);
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
