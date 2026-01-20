#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Add(int x, int y)//int 是返回类型
{
	int z = x + y;
	return z;
}
int main()
{
	int input = 0;
	printf("abc\ndef\n");
	printf("\?\?\?\n");
	printf("%c\n","");
	printf("\a");
	printf("------------\n");
	printf("%c\n", "\130");
	printf("%c\n", "\x0A");
	printf("%d\n", strlen("让我们加入比特"));
	printf("加入比特，你要写代码嘛？（1/0）：>");
	scanf("%d", &input);
	if (input == 1)

		printf("好offer\n");
	
	else
		printf("卖红薯\n");
	int line = 0;
	printf("-------------\n");
	while (line < 20000)
	{
		printf("敲代码：%d\n", line);
		line = line + 1;
	}
	if (line >= 20000)
		printf("好offer\n");

	int num1, num2, sum;
	scanf("%d %d", &num1, &num2);
	printf("%d\n", Add(num1, num2));

	return 0;

}