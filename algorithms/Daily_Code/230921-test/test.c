//#include  <stdio.h>
//#include  <string.h>
//#include  <ctype.h>
//int fun(char* s)
//{
//    int  sum = 0;
//    while (*s)
//    {
//        /**********found**********/
//        if (isdigit(*s))
//            sum += *s - 48;
//        /**********found**********/
//        s++;
//    }
//    /**********found**********/
//    return  sum;
//}
//void main()
//{
//    char  s[81];
//    int  n;
//    printf("\nEnter a string:\n\n");
//    gets_s(s,81);
//    n = fun(s);
//    printf("\nThe result is:  %d\n\n", n);
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void fun(int(*s)[10], int* b, int* n, int mm, int nn)
{
	int x, y, z = 0;
	for (y = 0;y < nn;y++)
	{
		for (x = 0;x < mm;x++)
		{
			b[*n] = *(*(s + x) + y);
			*n = *n + 1;
		}
	}
}
void main()
{
	int w[10][10] = { {33,33,33,33},{44,44,44,44},{55,55,55,55} }, i, j;
	int a[100] = { 0 }, n = 0;
	FILE* out;
	printf("The matrix:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0;j < 4;j++)
			printf("%3d", w[i][j]);
		printf("\n");
	}
	fun(w, a, &n, 3, 4);
	/******************************/
	out = fopen("out.dat", "w");
	printf("The A array:\n");
	for (i = 0; i < n; i++)
	{
		printf("%3d", a[i]);
		fprintf(out, "%d ", a[i]);
	}
	printf("\n\n");
	fclose(out);
	/******************************/
}