
/*  编译环境   汉字转换为UTF-8
	gcc version 5.4.0 20160609  
*/
#include <stdio.h>

//int global_val ;
//int global_val ;

int main(int argc, char *argv[])
{
	printf("Begin...\n");
    int val=0;
    for(int i=1; i <10; i++)
	{
		for(int j=1;i<10; j++)
		{
			
			val = i+j;
		}	
    }
    printf("val = %d\n",val);
    printf("End...\n");
    
    return 0;
}

