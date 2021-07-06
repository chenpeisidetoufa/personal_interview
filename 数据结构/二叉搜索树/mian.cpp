//1.每个节点中数据带一个唯一的关键
//2.创建的规律：如果插入的节点比当前节点的关键字大，放在当前节点右边，反之，左边，也就是左节点比父节点小，右节点比父节点大
//3.二叉搜索树任何一个子树依旧是一个二叉搜索树


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//键值对
typedef struct dataPair
{
	//关键字
	int first;
	//数据以字符串为例
	char second[20];
}DATA, *LPDATA;

//二叉树的结构体
typedef struct treeNode
{
	DATA data;
	struct  treeNode* LChild;
	struct  treeNode* RChild;
}NODE, *LPNODE;

//封装一个结构描述二叉搜索树
typedef struct binarySearchTree
{
	//根节点指针
	LPNODE root;
	//万金油参数
	int treeSize;
}BST, *LPBST;

//创建过程就是描述一种结构的最初的状态
LPBST createBST() 
{
	LPBST tree = (LPBST)malloc(sizeof(BST));
	tree->root = NULL;
	tree->treeSize = 0;
	return tree;
}

//我们做任何结构的插入：为插入做准备-->创建结点的过程
LPNODE createNode(DATA data)
{
	LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}

//万金油函数
int Size(LPBST tree) 
{
	return tree->treeSize;
}
bool isEmpty(LPBST tree)
{
	return tree->treeSize == 0;
}

//中序遍历，中序遍历出来是有序的
void printNode(LPNODE curNode)
{
	printf("%d:%s\n", curNode->data.first, curNode->data.second);
}
//递归
void midOrder(LPNODE tree)
{
	if (tree != NULL)
	{
		midOrder(tree->LChild);
		printNode(tree);
		midOrder(tree->RChild);
	}
}

void insertNode(LPBST tree, DATA data)
{
	//创建插入的节点
	LPNODE newNode = createNode(data);
	//找到合适的位置----->根据规则去找合适的位置
	//移动指针，从根节点开始
	LPNODE pMove = tree->root;
	//当前移动指针的父节点
	LPNODE pMoveParent = NULL;

	while (pMove != NULL)
	{
		//首先记录父节点
		pMoveParent = pMove;
		if (data.first < pMove->data.first)
		{
			pMove = pMove->LChild;
		}
		else if (data.first > pMove->data.first)
		{
			pMove = pMove->RChild;
		}
		else //相等覆盖原来的数据
		{
			strcpy(pMove->data.second, data.second);
			return;
		}
	}

	//树等于空树
	if (tree->root == NULL)
	{
		tree->root = newNode;
	}
	else //考虑插在pMoveParent的左边还是右边
	{
		if (pMoveParent->data.first > data.first)
		{
			pMoveParent->LChild = newNode;
		}
		else
		{
			pMoveParent->RChild = newNode;
		}
	}
	tree->treeSize++;
}  

//BST的查找
LPNODE searchBST(LPBST tree, int first)
{
	LPNODE pMove = tree->root;
	if (pMove == NULL)
	{
		return pMove;
	}
	else
	{
		while (pMove != NULL && pMove->data.first != first)
		{
			if (pMove->data.first > first)
			{
				pMove = pMove->LChild;
			}
			else
			{
				pMove = pMove->RChild;
			}
		}
		return pMove;
	}
}

int main()
{
	LPBST tree = createBST();
	DATA array[8] = { 20,"a",10,"b",13,"c" ,17,"d" ,1,"e" ,55,"f" ,70,"g" ,5,"h" };
	for (int i = 0;  i < sizeof(array)/sizeof(*array); i++)
	{
		insertNode(tree, array[i]);
	}
	midOrder(tree->root);

	int searchKey = 20;
	printf("%s%d\n", "查找", searchKey);
	if (searchBST(tree, searchKey))
	{
		printNode(searchBST(tree, searchKey));
	}
	else
	{
		printf("未找到\n");
	}

	system("pause");
	return 0;
}