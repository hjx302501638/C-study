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

/*C ���ִ���
	�����ļ���add.c
	int add(int a,int b)
	{
		return a+b;
	}
	������add.h
	int add(int a,int b);//�Ժ�����������
	ʹ��C�������add.c ���б���	gcc -c add.c -o add.o	����.o�ļ� 
	nm add.o //add.o�еķ��ű���Ϣ
	������main.cpp
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
	���룺g++ main.cpp add.o
	���������Ϣ��
	/tmp/cc6HoeKB.o: In function `main':
	main.cpp:(.text+0x2d): undefined reference to `add(int, int)'
	collect2: error: ld returned 1 exit status
	
	�����������Կ���	add ���������û�ж���ġ�
	
	�޸�main.cpp	ʹ�ùؼ���extern "C" {}
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