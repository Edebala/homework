#include <string.h>
#include <stdlib.h>

int charCompare(const void* a,const void* b)
{
	return *((char*)a) - *((char*)b);
}
int intCompare(const void* a,const void* b)
{
	return *((int*)a) - *((int*)b);
}
int floatCompare(const void* a,const void* b)
{
	return *((float*)a) - *((float*)b);
}
int stringCompare(const void* a,const void* b)
{
	return strcmp((char*)a,(char*)b);
}
