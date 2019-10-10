#include <stdio.h>

class Test
{
	private:
	int i;
	int j;
	public :
	int get_i(void)	{return i;}
	int get_j(void)	{return j;}
};

Test Ta;//�ھ�̬�洢���ж��� Test��

int main(int argc, char *argv[])
{
	printf("Ta.i = %d\n",Ta.get_i());//Ta.i = 0
	printf("Ta.j = %d\n",Ta.get_j());//Ta.j = 0

	Test Tb;//��ջ�϶�����
	printf("Tb.i = %d\n",Tb.get_i());//Tb.i = �����
	printf("Tb.j = %d\n",Tb.get_j());//Tb.j = �����
	
	Test *Tc = new Test;//�ڶ��϶�����
	printf("Tc->i = %d\n",Tc->get_i());//Tc.i = �����
	printf("Tc->j = %d\n",Tc->get_j());//Tc.i = �����
	
	return 0;
}


1������Intarray.h
#ifndef __INTARRAY_H
#define __INTARRAY_H
class intArray
{
	private:
	int arrayLenght;
	int *Parray;
	public:
	intArray (int lenght);//���캯��
	bool changeArray(int index,int val);//�޸������е�Ԫ��
	int getLenght(void);//��ȡ���鳤��
	bool getArrayData(int index,int& val);//��ȡ�����е�Ԫ��
	void free();
};


#endif 



2������Intarray.cpp
#include "intArray.h"

intArray::intArray (int lenght)//���캯��
{
	Parray = new int[lenght];//��������ռ�
	for(int i=0; i<lenght; i++)//��ʼ��
	Parray[i] = 0;
	arrayLenght = lenght;
}
bool intArray::changeArray(int index,int val)//�޸������е�Ԫ��
{
	bool ret = (index>=0)&&(index < arrayLenght);//�ж��Ƿ�Խ��
	if(ret)
	{
		Parray[index] = val;
	}
	return ret;
}
int intArray::getLenght(void)//��ȡ���鳤��
{
	return arrayLenght;
}
bool intArray::getArrayData(int index, int& val)//��ȡ�����е�Ԫ��
{
	bool ret = (index>=0)&&(index < arrayLenght);//�ж��Ƿ�Խ��
	if(ret)
	{
		val =  Parray[index] ;
	}
	return ret;
}

void intArray::free()//
{
	delete[] Parray;
}


3������main.cpp
#include <stdio.h>
#include "intArray.h"


int main(int argc, char *argv[])
{
	int temp ;
	intArray TestArray(6);
	for(int i=0; i<TestArray.getLenght();i++)
		TestArray.changeArray(i,i);
	for(int i=0; i<TestArray.getLenght();i++)
	{
		if(TestArray.getArrayData(i,temp))
		printf("getArrayData(%d) = %d\n",i,temp);
	}
	if(TestArray.getArrayData(100,temp))
	printf("getArrayData(%d) = %d\n",100,temp);
	TestArray.free();
	return 0;
}
