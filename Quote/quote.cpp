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