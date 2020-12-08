#ifndef MATRIXIO
#define MATRIXIO
int *readIntArray(char*, int*);
float *readFloatArray(char*, int*);
char *readCharArray(char*, int*);
char **readStringArray(char*, int*);
int **readArrayTwo(char*, int*,int*);
int **generateIntArrayTwo(int,int);
void printIntArray(int,const void*, char*);
void printIntArrayHex(int,const void*, char*);
void printUnsignedArray(int,const void*, char*);
void printFloatArray(int,const void*, char*);
void printCharArray(int,const void*, char*);
void printStringArray(int,const void*, char*);
void printIntArrayTwo(int, int,const void**,char*);
void printIntArrayTwoHex(int, int,const void**,char*);
void printUnsignedArrayTwo(int, int,const void**,char*);
void printSpiral(int,int,int**);
unsigned** parity(int,int,int**);
unsigned* rowParity(int,int,int**);
#endif
