//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//class ClassA
//{
//public:
//	ClassA()
//		:a(1)
//	{
//		cout << "ClassA()" << endl;
//	}
//	~ClassA()
//	{
//		cout << "~ClassA()" << endl;
//	}
//	void func()
//	{
//		cout << "void func()" << endl;
//	}
//	int a;
//};
//
//template<class T1,typename T2>
//int main()
//{
//	//ClassA* pclassa = new ClassA[5];
//	ClassA* pclassa = (ClassA*)malloc(sizeof(ClassA)*5);
//	if (pclassa == NULL)
//	{
//		return -1;
//	}
//	cout << pclassa[0].a << endl;
//	free(pclassa);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//typedef const char*(*haha)[10];
//
//int main()
//{
//	int num = 0;
//	int arr[10][10] = { 0 };
//	for (int i = 0;i < 10;i++)
//	{
//		for (int j = 0;j < 10;j++)
//		{
//			arr[i][j] = (num++);
//		}
//	}
//
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

int globalVar = 1;
static int staticGlobalVar = 1;
void Test()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	const char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);

	cout << "sizeof(num1)=" << sizeof(num1) << endl;
	cout << "sizeof(char2)=" << sizeof(char2) << endl;
	cout << "strlen(char2)=" << strlen(char2) << endl;
	cout << "sizeof(pChar3)=" << sizeof(pChar3) << endl;
	cout << "strlen(pChar3)=" << strlen(pChar3) << endl;
	cout << "sizeof(ptr1)=" << sizeof(ptr1) << endl;

	free(ptr1);
	free(ptr3);
}

int main()
{
	Test();
	return 0;
}