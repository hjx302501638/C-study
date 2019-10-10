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

Test Ta;//在静态存储区中定义 Test类

int main(int argc, char *argv[])
{
	printf("Ta.i = %d\n",Ta.get_i());//Ta.i = 0
	printf("Ta.j = %d\n",Ta.get_j());//Ta.j = 0

	Test Tb;//在栈上定义类
	printf("Tb.i = %d\n",Tb.get_i());//Tb.i = 随机数
	printf("Tb.j = %d\n",Tb.get_j());//Tb.j = 随机数
	
	Test *Tc = new Test;//在堆上定义类
	printf("Tc->i = %d\n",Tc->get_i());//Tc.i = 随机数
	printf("Tc->j = %d\n",Tc->get_j());//Tc.i = 随机数
	
	return 0;
}


1、创建Intarray.h
#ifndef __INTARRAY_H
#define __INTARRAY_H
class intArray
{
	private:
	int arrayLenght;
	int *Parray;
	public:
	intArray (int lenght);//构造函数
	bool changeArray(int index,int val);//修改数组中的元素
	int getLenght(void);//获取数组长度
	bool getArrayData(int index,int& val);//获取数组中的元素
	void free();
};


#endif 



2、创建Intarray.cpp
#include "intArray.h"

intArray::intArray (int lenght)//构造函数
{
	Parray = new int[lenght];//创建数组空间
	for(int i=0; i<lenght; i++)//初始化
	Parray[i] = 0;
	arrayLenght = lenght;
}
bool intArray::changeArray(int index,int val)//修改数组中的元素
{
	bool ret = (index>=0)&&(index < arrayLenght);//判断是否越界
	if(ret)
	{
		Parray[index] = val;
	}
	return ret;
}
int intArray::getLenght(void)//获取数组长度
{
	return arrayLenght;
}
bool intArray::getArrayData(int index, int& val)//获取数组中的元素
{
	bool ret = (index>=0)&&(index < arrayLenght);//判断是否越界
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


3、创建main.cpp
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
