#define _CRT_SECURE_NO_WARNINGS
//void A()
//{
//
//}
//void B()
//{
//	A();//嵌套调用
//}
//int main()
//{
//	return 0;
////}
//#include <stdio.h>
//void Print(unsigned int n)
//{
//	if (n > 9)
//	{
//		Print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);
//	Print(num);
//	return 0;
//}
//#include <stdio.h>
////int Fib(int n)
////{
////	if (n <= 2)
////		return 1;
////	else
////		return Fib(n - 1) + Fib(n - 2);
////}
//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//
//int fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * fac(n - 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fib(n);
//	printf("%d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//
//int Fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}


//#include <stdio.h>
//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
////}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fib(n);
//	printf("%d\n", ret);
//	return 0;
//}



//#include <stdio.h>
//int func(int n, int k)
//{
//	while (k >= 1)
//	{
//		return n * func(n, k - 1);
//		k--;
//	}
//}
//int main()
//{
//	int n;
//	int k;
//	printf("谁的几次方？");
//	scanf("%d %d", &n, &k);
//	printf("结果是：%d", func(n, k));
//	return 0;
//}

//#include <stdio.h>
//int DigitSum(int n)
//{
//	while (n > 0)
//	{
//		return (n % 10) + (DigitSum(n / 10));
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", DigitSum(n));
//}
//
//#include <stdio.h>
//char reverse_string(char* string)
//{
//	int len = 0;
//	int left, right;
//	while (*(string + len) != '\0')
//	{
//		len++;
//	}
//	if (left != right)
//	{
//		left=
//	}
//	return *(string+len)+reverse_string()
//}


//#include <stdio.h>
//int strlen(char* string)
//{
//	int len = 0;
//	while (*(string + len) != '\0')
//	{
//		len++;//非递归
//	}
//	return len;
//}
//
//int main()
//{
//	char string[] = "hehehaha";
//	printf("%d", strlen(string));
//}

//#include <stdio.h>
//int strlen(char* string)
//{
//	if (*string != '\0')
//	{
//		return 1 + strlen(string + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char string[] = "haha";
//	printf("%d", strlen(string));
//}

//#include <stdio.h>
//int step(int n)
//{
//	int sum = 1;
//	while (n > 1)
//	{
//		sum = sum * n;
//		n--;
//	}
//	return sum;
//}
//
//#include <stdio.h>
//int step(int n)
//{
//	while (n >= 1)
//	{
//		return n * step(n - 1);
//	}
//}
//
//int main()
//{
//	int n;
//	printf("几的阶乘？");
//	scanf("%d", &n);
//	printf("%d", step(n));
//}
//
//#include <stdio.h>
//void prt(int n)
//{
//	if (n > 9)
//	{
//		prt(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	prt(n);
//}

#include <stdio.h>
void reverse_string(char* string)
{
    char arr1 = 0;
    int i = 0;
    if (*string == '\n');                           //判断第1个字符是否为’\n'，是则停止递归

    else
    {
        for (i = 0; *(string + i + 1) != '\0'; i++);   //计算新指针到'\0'的长度是i+1

        arr1 = *string;                              //先把新指针指向第一个地址里的数提*string出来放到arr1里     
        *string = *(string + i);                     //把最后面的数*(string + i)放在指向的第一个地址*string里

        for (; i > 1; i--)                           //从新指针第二个数到第i+1依次往后移
        {
            *(string + i) = *(string + i - 1);
        }

        *(string + i) = arr1;                        //把arr1里数赋值给第二个数

        reverse_string((string + 1));                //否则把（string+1）地址给新string指针
    }
}

int main()
{
    char arr[8] = "hahahehe";
    reverse_string(&arr);
    printf("%s", arr);S
}