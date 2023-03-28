#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int arr[21] = { 1,2 };
//	double sum = 0;
//	int i = 0;
//	for (i = 0;i < 19;i++)
//	{
//		arr[i + 2] = arr[i + 1] + arr[i];
//	}
//	for (i = 0;i < 20;i++)
//	{
//		sum += (((double)arr[i + 1]) / ((double)arr[i]));
//	}
//	printf("%.4lf", sum);
//	return 0;
//}

//#include <iostream>
//#include <stdio.h>
//using namespace std;
//int main()
//{
//	double a[100] = { 1,2 };
//	double sum = 0;
//	int i = 0;
//	for (i = 0;i <= 19;i++)
//	{
//		a[i + 2] = a[i + 1] + a[i];
//	}
//		
//	for (i = 0;i < 20;i++)
//	{
//		sum += (a[i + 1] / a[i]);
//		printf("%lf\n", sum);
//	}
//
//	printf("%lf", sum);
//	return 0;
//}

#define N 60
#define PAI 3.1415926
#include <stdio.h>
#include <math.h>
double fac(int num)
{
	double s = 1;
	for (int i = 1;i <= num;i++)
	{
		s *= i;
	}
	return s;
}
int main()
{
	double sum = 1;
	int i = 1;
	double x = 0;
	scanf("%lf", &x);
	x = x * (PAI / 180);
	for (i = 1;i <= N;i++)
	{
		sum += (pow(-1, i) * (pow(x, 2 * (i+1) - 2) / fac(2 * (i+1) - 2)));
	}
	printf("cos(x)=%f", sum);
	return 0;
}