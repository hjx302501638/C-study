/*  ���뻷��   
	gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)
*/
#include <stdio.h>
int& func1(void)
{
	int a=5;
	return a;
}
//�൱��c �����е�
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
	//���н�������δ��� 
	//�����δ����ԭ���ǣ���Ϊ ��func1 ��a ��һ���ֲ���������ִ����ɺ󽫻ᱻ����
	//a ָ��һ�������ٵĿռ䣬��Ȼ����������ʹ��static �����ν�������ֶδ���
	//��Ϊʹ��static �Ὣ��������Ϊһ��ȫ�ֵı�����
	printf("a = %d\tb = %d\n",a,b);	//��ӡ��� a = δ֪��  b = 10
    printf("End...\n");
    return 0;
}




/*  ���뻷��   
    gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)
*/
#include <stdio.h>



void sewp_C(int *a, int *b) //ʹ��ָ����� a �� b ֮��Ľ�����
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void sewp_C_fun(int &a,int &b)//ʹ�� ����ʵ��  a �� b֮��Ľ���
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
    printf("a = %d\tb = %d\n",a,b);    //��ӡ��� a = 0 b = 1
    sewp_C_fun(a,b);
    printf("a = %d\tb = %d\n",a,b);    //��ӡ��� b = 1 a = 0
    printf("End...\n");
    return 0;
}




/*  ���뻷��   
    gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)
*/
#include <stdio.h>


int main(int argc, char *argv[])
{
    
    printf("Begin...\n");
    int a = 5;
    const int & b = a;
    int* p = (int*) &b;
    
    //b = 10;//����  ����ӵ��ֻ������
    *p = 20;
    printf("a = %d\tb = %d\n",a,b);    //��ӡ��� a = b = 20
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
    printf("sizeof(char &)  = %d\n",(int)sizeof(char &));  // ��ӡ����char &��ռ�õĴ�С  ռ��һ���ֽ�
    printf("sizeof(rc)  = %d\n",(int)sizeof(rc));          // rc ռ��һ���ֽ�
    printf("sizeof(Tqr)  = %d\n",(int)sizeof(Tqr));          //ռ��4���ֽ�        
    printf("sizeof(ref.r)  = %d\n",(int)sizeof(ref.r));    //ref.r  ռ��1���ֽ� ���ַ�������
    printf("sizeof(p)  = %d\n",(int)sizeof(p)); 

    printf("End...\n");
    return 0;
}