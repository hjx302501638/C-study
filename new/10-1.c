#include <stdio.h>

/*动态内存分配*/
int main(int argc, char *argv[])
{
	int *pi  = new int(100);
	char *Pc = new char('c');
	int *p = new int[10];
	printf("Begin...\n");
	printf("*pi = %d\n",*pi);
	printf("*pc = %c\n",*Pc);
	for(int i = 0;i<10 ; i++)
	{
		p[i] = i;
		printf("p[%d] = %d\n",i,p[i]);	
	}
   	printf("End...\n");
	delete pi;
	delete Pc;
	delete[] p;
	return 0;
}



/*命名空间*/
#include <stdio.h>

namespace Frist
{
	int i = 1;
}

namespace seconde
{
	int i=10;
	namespace thirdly
	{
		struct p
		{
			int x;
			int y;
		};
	}
}

int main(int argc, char *argv[])
{
	using namespace Frist;     //使用 Frist整个命名空间
	using  seconde::thirdly::p;//使用seconde 命名空间中的 thirdly命名空间中的 结构体p
	printf("Begin...\n");
	printf("Frist::i = %d\n",i);//直接使用 Frist 中的变量i
	printf("seconde::i = %d\n",seconde::i);//使用seconde命名空间中的变量i  注意如果同时使用Frist 与seconde整个命名空间就不能直接使用变量i
	p thirdly_p ={1,2};//初始化 seconde 命名空间中的 thirdly命名空间中的 结构体p
	printf("p.x = %d\n",thirdly_p.x);//直接使用 thirdly_p.x
	printf("p.y = %d\n",thirdly_p.y);
   	printf("End...\n");
	
	return 0;
}


/*强制类型转换*/
#include <stdio.h>

void static_cast_demo(void)
{
	int i = 0x12345;
	char c = 'c';
	int* pi = &i;  //pi -> i
	char* pc = &c; //pc -> c
	
	c = static_cast<char>(i);//int i change to char c
	pc = static_cast<char*>(pi);//想通过 static_cast 将int 型指针转换为 char型指针。由于static_cast不能用于基本类型指针转换error
}

void const_cast_demo(void)
{
	const int& j = 1;//定义一个j引用常量，j拥有只读属性
    int& k = const_cast<int&>(j);//定义一个k，通过const_cast k去除了j所拥有的只读属性
    
    const int x = 2; //定义一个常量x   x拥有只读属性
    int& y = const_cast<int&>(x);//定义一个y 通过const_cast y去除了引用x时所拥有的只读属性，所以y是可变的
    
    int z = const_cast<int>(x);//想通过const_cast 来将x转换为一个int型变量，这不允许，因为const_cast 强制转换的目标只能是指针或者引用。error
    
    k = 5;
    
    printf("k = %d\n", k);
    printf("j = %d\n", j);
    
    y = 8;
    
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("&x = %p\n", &x);
    printf("&y = %p\n", &y);

}


void reinterpret_cast_demo()
{
    int i = 0;
    char c = 'c';
    int* pi = &i;
    char* pc = &c;
    
    pc = reinterpret_cast<char*>(pi);//将int* 类型指针 转换为 char*
    pi = reinterpret_cast<int*>(pc);//将char* 类型指针 转换为 int*
    pi = reinterpret_cast<int*>(i);//将int 类型转换为 int*类型指针
    c = reinterpret_cast<char>(i); //想 通过reinterpret_cast  将int型 转换为char型 普通类型转换使用static_cast error 
}

void dynamic_cast_demo()
{
    int i = 0;
    int* pi = &i;
    char* pc = dynamic_cast<char*>(pi);//dynamic_cast 只能用于整数与指针类型之间的相互转换，这里将 整数类型转换为 char*类型 error
}



int main(int argc, char *argv[])
{
	
	
	return 0;
}

