#ifndef MATRIXIO
#define MATRIXIO
int *readIntArray(char*, int*);
int *readFloatArray(char*, int*);
char *readCharArray(char*, int*);
char **readStringArray(char*, int*);
int **readArrayTwo(char*, int*,int*);
void printIntArray(int,const void*, char*);
void printFloatArray(int,const void*, char*);
void printCharArray(int,const void*, char*);
void printStringArray(int,const void*, char*);
void printIntArrayTwo(int, int,int**,char*);
void printSpiral(int,int,int**);
#endif
