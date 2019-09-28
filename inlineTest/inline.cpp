#include <stdio.h>

#define FUN(a,b) ((a) < (b) ? (a) : (b))

inline int fun(int a,int b)
{
	return a < b ? a : b; //如果a<b  成立 a=a 否则a=b
}

int main(int argc, char *argv[])
{
	int a = 1,b=2;
	int val = FUN(a,b);
	printf("Begin...\n");
	printf("val = %d\n",val);
	printf("a = %d\n",a);
	printf("b = %d\n",b);
    printf("End...\n");
    return 0;
}
