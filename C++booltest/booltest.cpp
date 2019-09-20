
/*  编译环境   
	gcc version 5.4.0 20160609  
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Begin...\n");
	
	int a = 10;
	int &b = a;
	//int &b = 1;  //报类型错误
	//float &b = a;//报类型错误
	
	printf("a = %d\t",a);	//运行结果  a = b = 10 a的地址 = b的地址
	printf("b = %d\n",b);

	printf("a = 0x%p\t",&a);				 
	printf("b = 0x%p\n",&b);
    
    return 0;
}


/*
	int a = 5;
	int b = 2;
	(a < b ? a:b) = 10; //运行结果  b=10  a=5 
	(a < b ? a:1) = 10; //将会报错
	printf("a = %d\t",a);				 
	printf("b = %d\n",b);
	
	
*/

	bool a = false;
	int  b = 10;
	
	printf("bool size = %d\n",(int)sizeof(a));//打印bool变量的大小
	/*a = 0 b = 10*/
	printf("a = %d\t",a);				 
	printf("b = %d\n",b);				 
	/*a = 1 b=1*/
	a = b;
	b = a;
	printf("a = %d\t",a);				 
	printf("b = %d\n",b);				 
	
	/*a = 0 b=0*/
	b = 0;
	a = b;
	printf("a = %d\t",a);				 
	printf("b = %d\n",b);				 
	
	/*a = 1 b =10*/
	b+=10;
	a = b;
	printf("a = %d\t",a);				 
	printf("b = %d\n",b);				 
	
	/*a = 1 b=1*/
	a +=10;
	b = a;
	printf("a = %d\t",a);				 
	printf("b = %d\n",b);				 

/*
	int a = 10;
	int &b = a;
	//int &b = 1;  //报类型错误
	//float &b = a;//报类型错误
	
	printf("a = %d\t",a);	//运行结果  a = b = 10 a的地址 = b的地址
	printf("b = %d\n",b);

	printf("a = 0x%p\t",&a);				 
	printf("b = 0x%p\n",&b);
	
	#if 0
	a+=10;
	printf("a = %d\t",a);	//运行结果  a = b = 20 a的地址 = b的地址
	printf("b = %d\n",b);

	printf("a = 0x%p\t",&a);				 
	printf("b = 0x%p\n",&b);
	#endif
*/
