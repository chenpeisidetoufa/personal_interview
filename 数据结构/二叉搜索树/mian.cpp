//1.ÿ���ڵ������ݴ�һ��Ψһ�Ĺؼ�
//2.�����Ĺ��ɣ��������Ľڵ�ȵ�ǰ�ڵ�Ĺؼ��ִ󣬷��ڵ�ǰ�ڵ��ұߣ���֮����ߣ�Ҳ������ڵ�ȸ��ڵ�С���ҽڵ�ȸ��ڵ��
//3.�����������κ�һ������������һ������������


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ֵ��
typedef struct dataPair
{
	//�ؼ���
	int first;
	//�������ַ���Ϊ��
	char second[20];
}DATA, *LPDATA;

//�������Ľṹ��
typedef struct treeNode
{
	DATA data;
	struct  treeNode* LChild;
	struct  treeNode* RChild;
}NODE, *LPNODE;

//��װһ���ṹ��������������
typedef struct binarySearchTree
{
	//���ڵ�ָ��
	LPNODE root;
	//����Ͳ���
	int treeSize;
}BST, *LPBST;

//�������̾�������һ�ֽṹ�������״̬
LPBST createBST() 
{
	LPBST tree = (LPBST)malloc(sizeof(BST));
	tree->root = NULL;
	tree->treeSize = 0;
	return tree;
}

//�������κνṹ�Ĳ��룺Ϊ������׼��-->�������Ĺ���
LPNODE createNode(DATA data)
{
	LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}

//����ͺ���
int Size(LPBST tree) 
{
	return tree->treeSize;
}
bool isEmpty(LPBST tree)
{
	return tree->treeSize == 0;
}

//���������������������������
void printNode(LPNODE curNode)
{
	printf("%d:%s\n", curNode->data.first, curNode->data.second);
}
//�ݹ�
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
	//��������Ľڵ�
	LPNODE newNode = createNode(data);
	//�ҵ����ʵ�λ��----->���ݹ���ȥ�Һ��ʵ�λ��
	//�ƶ�ָ�룬�Ӹ��ڵ㿪ʼ
	LPNODE pMove = tree->root;
	//��ǰ�ƶ�ָ��ĸ��ڵ�
	LPNODE pMoveParent = NULL;

	while (pMove != NULL)
	{
		//���ȼ�¼���ڵ�
		pMoveParent = pMove;
		if (data.first < pMove->data.first)
		{
			pMove = pMove->LChild;
		}
		else if (data.first > pMove->data.first)
		{
			pMove = pMove->RChild;
		}
		else //��ȸ���ԭ��������
		{
			strcpy(pMove->data.second, data.second);
			return;
		}
	}

	//�����ڿ���
	if (tree->root == NULL)
	{
		tree->root = newNode;
	}
	else //���ǲ���pMoveParent����߻����ұ�
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

//BST�Ĳ���
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
	printf("%s%d\n", "����", searchKey);
	if (searchBST(tree, searchKey))
	{
		printNode(searchBST(tree, searchKey));
	}
	else
	{
		printf("δ�ҵ�\n");
	}

	system("pause");
	return 0;
}