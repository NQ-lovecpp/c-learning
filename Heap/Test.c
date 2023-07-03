#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"
//int main()
//{
//	HP hp;
//	HeapInit(&hp);
//	int a[] = { 65,100,70,32,50,60 };
//	for (int i = 0;i < (sizeof(a) / sizeof(int));i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	for (int i = 0;i < hp.size;i++)
//	{
//		printf("%d ", hp.a[i]);
//	}
//	HeapPop(&hp);
//	printf("\n");
//	for (int i = 0;i < hp.size;i++)
//	{
//		printf("%d ", hp.a[i]);
//	}
//	return 0;
//}


//void HeapSort(int* a, int n)
//{
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0;i < n;i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	int i = 0;
//	while (!HeapEmpty(&hp))
//	{
//		int top = HeapTop(&hp);
//		a[i++] = top;
//		HeapPop(&hp);
//	}
//	HeapDestroy(&hp);
//}

void HeapSort(int* a, int n)
{
	//升序==建立大堆
	//降序==建立小堆

	//建立堆==向上调整建堆
	for (int i = 1;i < n;i++)
	{
		AdjustUp(a, i);
	}

	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end]);

		AdjustDown(a, end, 0);
		--end;
	}
}
//int main()
//{
//	int a[] = { 7,8,3,5,1,9,5,4 };
//	HeapSort(a, sizeof(a) / sizeof(int));
//	for (int i = 0;i < sizeof(a) / sizeof(int);i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}

void PrintTopK(int k)
{
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	int* kminheap = (int*)malloc(sizeof(int) * k);
	if (kminheap == NULL)
	{
		perror("malloc fail");
		return;
	}

	for (int i = 0;i < k;i++)
	{
		fscanf(fout, "%d", &kminheap[i]);
	}

	//建立小堆
	for (int i = (k - 2) / 2;i >= 0;i--)
	{
		AdjustDown(kminheap, k, i);
	}

	int val = 0;
	while (!feof(fout))
	{
		fscanf(fout, "%d", &val);
		if (val > kminheap[0])
		{
			kminheap[0] = val;
			AdjustDown(kminheap, k, 0);
		}
	}
	for (int i = 0;i < k;i++)
	{
		printf("%d ",kminheap[i]);
	}
	printf("\n");
}


void CreatNData()
{
	int n = 1000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	
	for (size_t i = 0;i < n;i++)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

//int main()
//{
//	CreatNData();
//	PrintTopK(5);
//
//	return 0;
//}

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL; 
	return node;
}
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	return node1;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);

}
int main()
{
	BTNode* root = CreatBinaryTree();
	PrevOrder(root);
	printf("\n");
	return 0;
}