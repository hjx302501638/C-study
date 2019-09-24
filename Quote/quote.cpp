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




/*  编译环境   
    gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)
*/
#include <stdio.h>



void sewp_C(int *a, int *b) //使用指针进行 a 和 b 之间的交换。
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void sewp_C_fun(int &a,int &b)//使用 引用实现  a 和 b之间的交换
{
    int t = a;
    a = b;
    b = t;
}

int main(int argc, char *argv[])
{
    int a = 1,b = 0;
    printf("Begin...\n");
    sewp_C(&a,&b);    
    printf("a = %d\tb = %d\n",a,b);    //打印结果 a = 0 b = 1
    sewp_C_fun(a,b);
    printf("a = %d\tb = %d\n",a,b);    //打印结果 b = 1 a = 0
    printf("End...\n");
    return 0;
}




/*  编译环境   
    gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)
*/
#include <stdio.h>


int main(int argc, char *argv[])
{
    
    printf("Begin...\n");
    int a = 5;
    const int & b = a;
    int* p = (int*) &b;
    
    //b = 10;//错误  变量拥有只读属性
    *p = 20;
    printf("a = %d\tb = %d\n",a,b);    //打印结果 a = b = 20
    printf("End...\n");

    return 0;
}


#include <stdio.h>

struct Tqr 
{
    char & r;
};

int main(int argc, char *argv[])
{
    char c = 'c';
    char & rc = c;
    Tqr ref ={c};
    int *p;
    printf("Begin...\n");
    printf("sizeof(char &)  = %d\n",(int)sizeof(char &));  // 打印变量char &所占用的大小  占用一个字节
    printf("sizeof(rc)  = %d\n",(int)sizeof(rc));          // rc 占用一个字节
    printf("sizeof(Tqr)  = %d\n",(int)sizeof(Tqr));          //占用4个字节        
    printf("sizeof(ref.r)  = %d\n",(int)sizeof(ref.r));    //ref.r  占用1个字节 （字符变量）
    printf("sizeof(p)  = %d\n",(int)sizeof(p)); 

    printf("End...\n");
    return 0;
}