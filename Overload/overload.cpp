#include <stdio.h>
#include <string.h>

#if 0
int func(int x)
{
	return x;
}

int func(int x,int y)
{
	return x + y;
}

int func(const char *s)
{
	return strlen(s);
}



int main(int argc, char *argv[])
{
	printf("Begin...\n");
	printf("%d\n" ,func(1));
	printf("%d\n" ,func(2));
	printf("%d\n" ,func("abcdefg"));
    printf("End...\n");
    return 0;
}

#endif 


#if 0
int func(const char *s ,int a)
{
	return a;
}

int func(int a,const char *s )
{
	return strlen(s);
}


int main(int argc, char *argv[])
{
	printf("Begin...\n");
	printf("%d\n" func("abc",2));
	printf("%d\n" func("abc",2));
    printf("End...\n");
    return 0;
}

#endif

#if 0
int func(int a,int b)
{
	return a + b;
}

int func(int a,int b,int c=10)
{
	return a+b+c;
}


int main(int argc, char *argv[])
{
	printf("Begin...\n");
	//printf("%d\n" func(1,2));
    printf("End...\n");
    return 0;
}

#endif 

#if 0
int func(int a,int b)
{
	return a + b;
}

int func(int a,int b,int c=10)
{
	return a+b+c;
}

int func(const char *s)
{
	return strlen(s);
}	

typedef int (*Pfunc) (int a,int b);

int main(int argc, char *argv[])
{
	printf("Begin...\n");
	Pfunc P= func;
	int c = 0;
	c = P(1,2);
	printf("c = %d\n",c);
	printf("%p\n",(int(*)(int,int))func);
    printf("End...\n");
    return 0;
}

#endif

/*C 部分代码
	创建文件：add.c
	int add(int a,int b)
	{
		return a+b;
	}
	创建：add.h
	int add(int a,int b);//对函数进行声明
	使用C编译进行add.c 进行编译	gcc -c add.c -o add.o	生成.o文件 
	nm add.o //add.o中的符号表信息
	创建：main.cpp
	#include <stadio.h>
	#include "add.h"
	int main(int argc, char *argv[])
	{
		printf("Begin...\n");
		int c = 0;
		c = add(10,20)
		printf("c = %d\n",c);
		printf("End...\n");
		return 0;
	}
	编译：g++ main.cpp add.o
	输出错误信息：
	/tmp/cc6HoeKB.o: In function `main':
	main.cpp:(.text+0x2d): undefined reference to `add(int, int)'
	collect2: error: ld returned 1 exit status
	
	从上面错误可以看出	add 这个函数是没有定义的。
	
	修改main.cpp	使用关键字extern "C" {}
	#include <stadio.h>
	extern "C"
	{
		#include "add.h"
	}
	int main(int argc, char *argv[])
	{
		printf("Begin...\n");
		int c = 0;
		c = add(10,20)
		printf("c = %d\n",c);
		printf("End...\n");
		return 0;
	}

*/