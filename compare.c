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
	float c = *((float*)a) - *((float*)b);
	return abs(c)>0.0001?c:0;
}
int stringCompare(const void* a,const void* b)
{
	return strcmp((const char*)a,(const char*)b);
}
