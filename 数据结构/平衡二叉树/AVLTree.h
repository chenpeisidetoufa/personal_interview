#pragma once

//平衡二叉树节点类型
template<class T>
struct TreeNode 
{
	T data;    //数据
	TreeNode *pLeft; //左孩子
	TreeNode *pRight; //右孩子
	int height; //高度，实际插入过程中，一旋转会产生错误高度，但是会在逐步的插入过程中修正，但是此变量主要用来判断是否需要旋转，虽然过程中有可能不等于树的实际高度，但是不影响其判断正确，因为可以理解为一种控制旋转的平衡因子
	
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

	//右旋对应情况1
	TreeNode<T>* RR(TreeNode<T>* pRoot);
	//左旋对应情况2
	TreeNode<T>* LL(TreeNode<T>* pRoot);
	//左右旋对应情况3
	TreeNode<T>* LR(TreeNode<T>* pRoot);
	//有左旋对应情况4
	TreeNode<T>* RL(TreeNode<T>* pRoot);
public:
	AVLTree() { pRoot = NULL; } //无参构造，内联
	~AVLTree() {} //析构 没有实现！

	void insert(const T& data);
};


template<class T>
TreeNode<T>* AVLTree<T>::RR(TreeNode<T>* pRoot)
{
	cout << "右旋" << endl;
	TreeNode<T>* temp = pRoot->pLeft;
	pRoot->pLeft = temp->pRight;
	temp->pRight = pRoot;
	return temp;
}

template<class T>
TreeNode<T>* AVLTree<T>::LL(TreeNode<T>* pRoot)
{
	cout << "左旋" << endl;
	TreeNode<T>* temp = pRoot->pRight; 
	pRoot->pRight = temp->pLeft; //temp->pLeft一定是大于pRoot小于temp，先将temp的左节点挂到pRoot的右节点上
	temp->pLeft = pRoot; //再将pRoot挂到temp->pLeft上，完成左旋
	return temp; //此时temp变为新树的根
}

template<class T>
TreeNode<T>* AVLTree<T>::LR(TreeNode<T>* pRoot)
{
	cout << "左右旋" << endl;
	TreeNode<T>* temp = pRoot->pLeft;
	pRoot->pLeft = LL(temp);
	return RR(pRoot);
}

template<class T>
TreeNode<T>* AVLTree<T>::RL(TreeNode<T>* pRoot)
{
	cout << "右左旋" << endl;
	TreeNode<T>* temp = pRoot->pRight;
	pRoot->pRight = RR(temp);
	return LL(pRoot);
}

template<class T>
void AVLTree<T>::insert(const T& data)
{
	insertNodeToTree(pRoot, data);
}





//获取此树某个节点开始的高度
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
// Qualifier: 递归插入
// Parameter: TreeNode<T> * & root 此root绑定AVLTree中的pRoot 
// Parameter: const T & data
//************************************
template<class T>
void AVLTree<T>::insertNodeToTree(TreeNode<T>*& root, const T& data)
{
	//作为一颗平衡二叉树，先是一颗有序二叉树

	//1 以有序二叉树方式插入
	
	//一直递归到root指针是NULL，插入数据
	if (NULL == root)
	{
		root = new TreeNode<T>(data);
	}
	else if (data > root->data)
	{
		insertNodeToTree(root->pRight, data);
		//2 检查是否需要旋转，需要就旋转
		//比较左右子树高度差是否大于1
		if (getHeight(root->pRight) - getHeight(root->pLeft) > 1) //检查是否右侧的子树高度与左侧子树的高度差是否>1
		{ 
			if (data > root->pRight->data)  //第2种情况
			{
				root = LL(root); //以root为轴左旋 然后 返回值赋值给root 修改根节点
			}
			else							//第4种情况
			{
				root = RL(root);
			}
			cout << "调整后的根：" << root->data << endl;
		}
	}
	else if (data < root->data)
	{
		insertNodeToTree(root->pLeft, data);
		if (getHeight(root->pLeft) - getHeight(root->pRight) > 1) //检查是否右侧的子树高度与左侧子树的高度差是否>1
		{
			if (data < root->pLeft->data)  //第1种情况
			{
				root = RR(root); //以root为轴右旋 然后 返回值赋值给root 修改根节点
			}
			else							//第3种情况
			{
				root = LR(root);
			}
			cout << "调整后的根：" << root->data << endl;
		}
	}
	else    //相等的情况,直接覆盖，或者什么都不干
	{
		root->data = data;
	}

	//设置高度
	int lh = getHeight(root->pLeft);
	int rh = getHeight(root->pRight);
	root->height = 1 + ((lh > rh) ? lh : rh);
}

