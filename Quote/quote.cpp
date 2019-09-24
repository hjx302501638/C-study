/*  编译环境   
	gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)
*/
#include <stdio.h>
int& func1(void)
{
	int a=5;
	return a;
}
//相当于c 语言中的
/*
	int * func1(void)
	{
		int a= 5;
		return &a;
	}
*/
int& func2(void)
{
	static int b = 10;
	return b;
}
/*
	int * func2(void)
	{
			static b = 10;
			return &b;
	}
*/
int main(int argc, char *argv[])
{
	int &a = func1();
	int &b = func2();
	printf("Begin...\n");
	//运行将会产生段错误 
	//产生段错误的原因是，因为 在func1 中a 是一个局部变量，在执行完成后将会被销毁
	//a 指向一个被销毁的空间，自然会出错。而如果使用static 来修饰将不会出现段错误。
	//因为使用static 会将变量声明为一个全局的变量。
	printf("a = %d\tb = %d\n",a,b);	//打印结果 a = 未知数  b = 10
    printf("End...\n");
    return 0;
}