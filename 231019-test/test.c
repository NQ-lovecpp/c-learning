#include <stdio.h>
struct tag
{
	int a;
}variable;

typedef int test1;

int main()
{
	struct tag t1 = { 1 };
	variable.a = 2;
	printf("%d", t1.a);
	printf("%d", variable.a);
	return 0;
}