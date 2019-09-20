
/*  编译环境   汉字转换为UTF-8
	gcc version 5.4.0 20160609  
*/
#include <stdio.h>

//int global_val ;
//int global_val ;
struct test_struct 
{
	int a;
	int b;
	int c;
};
int f(void)
{
	return 10;
}
int f1()
{
	return 11;
}
int main(int argc, char *argv[])
{
	test_struct S1 = {1,2,3};
	printf("Begin...\n");
    int val=0;
    for(int i=1; i <10; i++)
	{
		for(int j=1;j<10; j++)
		{
			
			val = i+j;
		}	
    }
 	int *p;
	p=&S1.a;
	for(int i=0;i <3 ;i++)
	printf("test_struct val_%d = %d\n",i,*p++);
	
	printf("f(void)= %d\n",f());
	printf("f(void)= %d\n",f1());
	const int const_val = 0;
	p = (int *)&const_val;
	*p = 10;
    	printf("const_val = %d\n",const_val);	
    	printf("val = %d\n",val);
    printf("val = %d\n",val);
    printf("End...\n");
    
    return 0;
}

