#define _CRT_SECURE_NO_WARNINGS

//写一个c语言程序，在屏幕打印hehe
//printf是一个库函数
#include <stdio.h>//标准输入输出头文件
int num = 10000000;
//void表示不需要传递参数
int main(void)//int说明main函数执行后会返回一个整型值 main函数是程序的入口
{
	int age = 10;
	float salary = 10000.0f;

	printf("%d\n", age);
	printf("%.5f\n", salary);//保留5位小数 不加默认保留6位小数
	printf("-------------------\n");
	printf("hehe\n");
	printf("%d\n", sizeof(char));//1byte
	printf("%d\n", sizeof(short));//2
	printf("%d\n", sizeof(int));//4
	printf("%d\n", sizeof(long));//4
	printf("%d\n", sizeof(long long));//8
	printf("%d\n", sizeof(float));//4
	printf("%d\n", sizeof(double));//8
	printf("-------------------\n");
	int num = 10;
	printf("%d\n",num);
	pprintf("--------------------------\n");
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	


	return 0;
}