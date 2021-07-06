#pragma once

//ƽ��������ڵ�����
template<class T>
struct TreeNode 
{
	T data;    //����
	TreeNode *pLeft; //����
	TreeNode *pRight; //�Һ���
	int height; //�߶ȣ�ʵ�ʲ�������У�һ��ת���������߶ȣ����ǻ����𲽵Ĳ�����������������Ǵ˱�����Ҫ�����ж��Ƿ���Ҫ��ת����Ȼ�������п��ܲ���������ʵ�ʸ߶ȣ����ǲ�Ӱ�����ж���ȷ����Ϊ�������Ϊһ�ֿ�����ת��ƽ������
	
	TreeNode() 
	{
		pLeft = pRight = NULL;
		height = 0;
	}
	TreeNode(const T& data) 
	{
		this->data = data;
		pLeft = pRight = NULL;
		height = 0;
	}
};

template<class T>
struct AVLTree
{
private:
	TreeNode<T>* pRoot;

	void insertNodeToTree(TreeNode<T>*& root, const T& data);
	int getHeight(TreeNode<T>*& pRoot);

	//������Ӧ���1
	TreeNode<T>* RR(TreeNode<T>* pRoot);
	//������Ӧ���2
	TreeNode<T>* LL(TreeNode<T>* pRoot);
	//��������Ӧ���3
	TreeNode<T>* LR(TreeNode<T>* pRoot);
	//��������Ӧ���4
	TreeNode<T>* RL(TreeNode<T>* pRoot);
public:
	AVLTree() { pRoot = NULL; } //�޲ι��죬����
	~AVLTree() {} //���� û��ʵ�֣�

	void insert(const T& data);
};


template<class T>
TreeNode<T>* AVLTree<T>::RR(TreeNode<T>* pRoot)
{
	cout << "����" << endl;
	TreeNode<T>* temp = pRoot->pLeft;
	pRoot->pLeft = temp->pRight;
	temp->pRight = pRoot;
	return temp;
}

template<class T>
TreeNode<T>* AVLTree<T>::LL(TreeNode<T>* pRoot)
{
	cout << "����" << endl;
	TreeNode<T>* temp = pRoot->pRight; 
	pRoot->pRight = temp->pLeft; //temp->pLeftһ���Ǵ���pRootС��temp���Ƚ�temp����ڵ�ҵ�pRoot���ҽڵ���
	temp->pLeft = pRoot; //�ٽ�pRoot�ҵ�temp->pLeft�ϣ��������
	return temp; //��ʱtemp��Ϊ�����ĸ�
}

template<class T>
TreeNode<T>* AVLTree<T>::LR(TreeNode<T>* pRoot)
{
	cout << "������" << endl;
	TreeNode<T>* temp = pRoot->pLeft;
	pRoot->pLeft = LL(temp);
	return RR(pRoot);
}

template<class T>
TreeNode<T>* AVLTree<T>::RL(TreeNode<T>* pRoot)
{
	cout << "������" << endl;
	TreeNode<T>* temp = pRoot->pRight;
	pRoot->pRight = RR(temp);
	return LL(pRoot);
}

template<class T>
void AVLTree<T>::insert(const T& data)
{
	insertNodeToTree(pRoot, data);
}





//��ȡ����ĳ���ڵ㿪ʼ�ĸ߶�
template<class T>
int AVLTree<T>::getHeight(TreeNode<T>*& pRoot)
{
	if (pRoot)
	{
		return pRoot->height;
	}
	else
	{
		return 0;
	}
	
}

//************************************
// Method:    insertNodeToTree
// FullName:  AVLTree<T>::insertNodeToTree
// Access:    private 
// Returns:   void
// Qualifier: �ݹ����
// Parameter: TreeNode<T> * & root ��root��AVLTree�е�pRoot 
// Parameter: const T & data
//************************************
template<class T>
void AVLTree<T>::insertNodeToTree(TreeNode<T>*& root, const T& data)
{
	//��Ϊһ��ƽ�������������һ�����������

	//1 �������������ʽ����
	
	//һֱ�ݹ鵽rootָ����NULL����������
	if (NULL == root)
	{
		root = new TreeNode<T>(data);
	}
	else if (data > root->data)
	{
		insertNodeToTree(root->pRight, data);
		//2 ����Ƿ���Ҫ��ת����Ҫ����ת
		//�Ƚ����������߶Ȳ��Ƿ����1
		if (getHeight(root->pRight) - getHeight(root->pLeft) > 1) //����Ƿ��Ҳ�������߶�����������ĸ߶Ȳ��Ƿ�>1
		{ 
			if (data > root->pRight->data)  //��2�����
			{
				root = LL(root); //��rootΪ������ Ȼ�� ����ֵ��ֵ��root �޸ĸ��ڵ�
			}
			else							//��4�����
			{
				root = RL(root);
			}
			cout << "������ĸ���" << root->data << endl;
		}
	}
	else if (data < root->data)
	{
		insertNodeToTree(root->pLeft, data);
		if (getHeight(root->pLeft) - getHeight(root->pRight) > 1) //����Ƿ��Ҳ�������߶�����������ĸ߶Ȳ��Ƿ�>1
		{
			if (data < root->pLeft->data)  //��1�����
			{
				root = RR(root); //��rootΪ������ Ȼ�� ����ֵ��ֵ��root �޸ĸ��ڵ�
			}
			else							//��3�����
			{
				root = LR(root);
			}
			cout << "������ĸ���" << root->data << endl;
		}
	}
	else    //��ȵ����,ֱ�Ӹ��ǣ�����ʲô������
	{
		root->data = data;
	}

	//���ø߶�
	int lh = getHeight(root->pLeft);
	int rh = getHeight(root->pRight);
	root->height = 1 + ((lh > rh) ? lh : rh);
}

