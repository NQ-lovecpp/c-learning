#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
	BTNode* node7 = BuyNode(7);
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->left = node7;
	return node1;
}

//前序遍历
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

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

// 二叉树节点个数
int BTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BTreeSize(root->left) + BTreeSize(root->right) + 1;
}

// 二叉树叶子节点个数
int BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BTreeLeafSize(root->left) + BTreeLeafSize(root->right);
}

//二叉树的高度
int BTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = BTreeHeight(root->left);
	int rightHeight = BTreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// 二叉树第k层节点个数
int BTreeLevelKSize(BTNode* root, int k)//第k层的节点数
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BTreeLevelKSize(root->left, k - 1)
		+ BTreeLevelKSize(root->right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return;
	}
	if (root->data = x)
	{
		return root;
	}
	BTNode* ret1 = BTreeFind(root->left, x);
	if (ret1)
	{
		return ret1;
	}
	BTNode* ret2 = BTreeFind(root->right, x);
	{
		return ret2;
	}
	return NULL;

}

int main()
{
	BTNode* root = CreatBinaryTree();
	InOrder(root);
	printf("\n");
	BTreeSize(root);
	printf("BTSize = %d\n", BTreeSize(root));
	printf("BTLeafSize = %d\n", BTreeLeafSize(root));
	printf("BTreeHeight = %d\n", BTreeHeight(root));
	printf("BTreeLeavlKSize = %d\n", BTreeLevelKSize(root,2));

	return 0;
}