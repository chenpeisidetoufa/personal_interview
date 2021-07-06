#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
	char data;
	struct treeNode* LChild;
	struct treeNode* RChild;
};

//创建树
struct  treeNode* createNode(char data)
{
	struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
};


//连接节点
void insertNode(struct treeNode* curNode, struct treeNode* LChildNode, struct treeNode* RChildNode) 
{
	//左边节点连接
	curNode->LChild = LChildNode;
	//右边节点连接
	curNode->RChild = RChildNode;
}

//打印表示遍历
void printData(struct treeNode* curNode)
{
	printf("%c\t", curNode->data);
}

//递归中序遍历
void midOrder(struct treeNode* tree)
{
	if (tree != NULL)
	{
		midOrder(tree->LChild);
		printData(tree);
		midOrder(tree->RChild);
	}
 }

//非递归方式实现中序遍历，通过栈实现
void midOrderByStake(struct treeNode* tree)
{
	//空数
	if (tree == NULL)
	{
		return;
	}
	//初始化一个栈
	struct treeNode* stake[10];
	int stakeTop = -1;   //为了使入栈的第一个元素正好对应数组下标stake[0]

	//移动指针，从根节点开始
	struct treeNode* pMove = tree;

	//当栈没有到栈底或者pMove不为空时
	while (stakeTop != -1 || pMove) 
	{
		//当pMove不为空时,找最左边，一条路走到底，
		while (pMove)
		{
			//走完路后，脚印留下
			stake[++stakeTop] = pMove;
			pMove = pMove->LChild;
		}
		//pMove == NULL 没有左边，去找右边
		//出栈，栈不能为空 
		if (stakeTop != -1)
		{
			//回退栈
			pMove = stake[stakeTop--];
			//打印
			printData(pMove);
			//向右去寻找
			pMove = pMove->RChild;
		}
	}
}


int main() 
{
	//创建
	struct treeNode* A = createNode('A');
	struct treeNode* B = createNode('B');
	struct treeNode* C = createNode('C');
	struct treeNode* D = createNode('D');
	struct treeNode* E = createNode('E');
	struct treeNode* F = createNode('F');
	struct treeNode* G = createNode('G');
	struct treeNode* K = createNode('K');

	//连接
	insertNode(A, B, C);
	insertNode(B, D, E);
	insertNode(C, F, G);
	insertNode(F, NULL, K);

	//遍历
	midOrder(A);
	printf("\n");
	midOrderByStake(A);
	printf("\n");

	system("pause");
	return 0;
}