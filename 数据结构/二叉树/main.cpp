#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
	char data;
	struct treeNode* LChild;
	struct treeNode* RChild;
};

//������
struct  treeNode* createNode(char data)
{
	struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
};


//���ӽڵ�
void insertNode(struct treeNode* curNode, struct treeNode* LChildNode, struct treeNode* RChildNode) 
{
	//��߽ڵ�����
	curNode->LChild = LChildNode;
	//�ұ߽ڵ�����
	curNode->RChild = RChildNode;
}

//��ӡ��ʾ����
void printData(struct treeNode* curNode)
{
	printf("%c\t", curNode->data);
}

//�ݹ��������
void midOrder(struct treeNode* tree)
{
	if (tree != NULL)
	{
		midOrder(tree->LChild);
		printData(tree);
		midOrder(tree->RChild);
	}
 }

//�ǵݹ鷽ʽʵ�����������ͨ��ջʵ��
void midOrderByStake(struct treeNode* tree)
{
	//����
	if (tree == NULL)
	{
		return;
	}
	//��ʼ��һ��ջ
	struct treeNode* stake[10];
	int stakeTop = -1;   //Ϊ��ʹ��ջ�ĵ�һ��Ԫ�����ö�Ӧ�����±�stake[0]

	//�ƶ�ָ�룬�Ӹ��ڵ㿪ʼ
	struct treeNode* pMove = tree;

	//��ջû�е�ջ�׻���pMove��Ϊ��ʱ
	while (stakeTop != -1 || pMove) 
	{
		//��pMove��Ϊ��ʱ,������ߣ�һ��·�ߵ��ף�
		while (pMove)
		{
			//����·�󣬽�ӡ����
			stake[++stakeTop] = pMove;
			pMove = pMove->LChild;
		}
		//pMove == NULL û����ߣ�ȥ���ұ�
		//��ջ��ջ����Ϊ�� 
		if (stakeTop != -1)
		{
			//����ջ
			pMove = stake[stakeTop--];
			//��ӡ
			printData(pMove);
			//����ȥѰ��
			pMove = pMove->RChild;
		}
	}
}


int main() 
{
	//����
	struct treeNode* A = createNode('A');
	struct treeNode* B = createNode('B');
	struct treeNode* C = createNode('C');
	struct treeNode* D = createNode('D');
	struct treeNode* E = createNode('E');
	struct treeNode* F = createNode('F');
	struct treeNode* G = createNode('G');
	struct treeNode* K = createNode('K');

	//����
	insertNode(A, B, C);
	insertNode(B, D, E);
	insertNode(C, F, G);
	insertNode(F, NULL, K);

	//����
	midOrder(A);
	printf("\n");
	midOrderByStake(A);
	printf("\n");

	system("pause");
	return 0;
}