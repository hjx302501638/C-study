#include <stdio.h>

/*��̬�ڴ����*/
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



/*�����ռ�*/
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
	using namespace Frist;     //ʹ�� Frist���������ռ�
	using  seconde::thirdly::p;//ʹ��seconde �����ռ��е� thirdly�����ռ��е� �ṹ��p
	printf("Begin...\n");
	printf("Frist::i = %d\n",i);//ֱ��ʹ�� Frist �еı���i
	printf("seconde::i = %d\n",seconde::i);//ʹ��seconde�����ռ��еı���i  ע�����ͬʱʹ��Frist ��seconde���������ռ�Ͳ���ֱ��ʹ�ñ���i
	p thirdly_p ={1,2};//��ʼ�� seconde �����ռ��е� thirdly�����ռ��е� �ṹ��p
	printf("p.x = %d\n",thirdly_p.x);//ֱ��ʹ�� thirdly_p.x
	printf("p.y = %d\n",thirdly_p.y);
   	printf("End...\n");
	
	return 0;
}


/*ǿ������ת��*/
#include <stdio.h>

void static_cast_demo(void)
{
	int i = 0x12345;
	char c = 'c';
	int* pi = &i;  //pi -> i
	char* pc = &c; //pc -> c
	
	c = static_cast<char>(i);//int i change to char c
	pc = static_cast<char*>(pi);//��ͨ�� static_cast ��int ��ָ��ת��Ϊ char��ָ�롣����static_cast�������ڻ�������ָ��ת��error
}

void const_cast_demo(void)
{
	const int& j = 1;//����һ��j���ó�����jӵ��ֻ������
    int& k = const_cast<int&>(j);//����һ��k��ͨ��const_cast kȥ����j��ӵ�е�ֻ������
    
    const int x = 2; //����һ������x   xӵ��ֻ������
    int& y = const_cast<int&>(x);//����һ��y ͨ��const_cast yȥ��������xʱ��ӵ�е�ֻ�����ԣ�����y�ǿɱ��
    
    int z = const_cast<int>(x);//��ͨ��const_cast ����xת��Ϊһ��int�ͱ������ⲻ������Ϊconst_cast ǿ��ת����Ŀ��ֻ����ָ��������á�error
    
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
    
    pc = reinterpret_cast<char*>(pi);//��int* ����ָ�� ת��Ϊ char*
    pi = reinterpret_cast<int*>(pc);//��char* ����ָ�� ת��Ϊ int*
    pi = reinterpret_cast<int*>(i);//��int ����ת��Ϊ int*����ָ��
    c = reinterpret_cast<char>(i); //�� ͨ��reinterpret_cast  ��int�� ת��Ϊchar�� ��ͨ����ת��ʹ��static_cast error 
}

void dynamic_cast_demo()
{
    int i = 0;
    int* pi = &i;
    char* pc = dynamic_cast<char*>(pi);//dynamic_cast ֻ������������ָ������֮����໥ת�������ｫ ��������ת��Ϊ char*���� error
}



int main(int argc, char *argv[])
{
	
	
	return 0;
}

