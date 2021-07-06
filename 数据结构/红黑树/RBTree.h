//特性：
//（1）每个节点是黑色或者是红色
//（2）根节点是黑色
//（2）每个叶子节点（NULL）是黑丝
//（3）如果一个节点是红色，则它的子节点必须是黑色
//（5）从一个节点到该节点的子孙节点的所有路径上包含相同数目的黑节点，此特性确保了没有一条路径会比其他路径长出两倍。因此，红黑树是相对接近平衡的二叉树

/*
 * 左旋：
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(左旋)-->           / \                
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */

 /*
  * 右旋：
  *            py                               py
  *           /                                /
  *          y                                x
  *         /  \      --(右旋)-->            /  \                    
  *        x   ry                           lx   y
  *       / \                                   / \                 
  *      lx  rx                                rx  ry
  *
  */

  //插入操作：
  //为了满足特性（5），插入的时候总是默认先将插入节点涂红
  //情况1：插入根节点，原来是空树，涂黑即可
  //情况2：插入后的节点的父节点是黑色的，什么都不用做
  //情况3：插入后的父节点是红色的，并且叔叔节点也是红色--------对策：将当前节点的父节点和叔叔节点涂黑，祖父节点涂红,再以祖父节点继续循环
  //情况4：当前节点的父节点是红色，叔叔节点是黑色，当前节点是其父节点的右子节点
  //       对策：1）父节点是祖父节点的左节点：1.以父节点作为支点左旋；2.再以父节点继续----------调整后必为情况5
  //             2）父节点是祖父节点的右节点：1.父节点涂黑；2.祖父节点涂红；3.以祖父节点为支点左旋；4.节点保持不变继续循环
  //情况5：当前节点的父节点是红色，叔叔节点是黑色，当前节点是其父节点的左子节点
  //       对策：1）父节点是祖父节点的左节点：1.父节点涂黑；2.祖父节点涂红；3.以祖父节点为支点右旋；4.节点保持不变继续循环
  //             2）父节点是祖父节点的右节点：1.以父节点作为支点右旋；2.再以父节点继续----------调整后必为情况4
  //排除了情况3、4、5后，跳出循环，最后将根节点涂黑


#ifndef _RED_BLACK_TREE_HPP
#define _RED_BLACK_TREE_HPP

#include<iomanip> //I/O流控制头文件
#include <iostream>
using namespace std;

//颜色枚举
enum RBTColor
{
	RED,
	BLACK
};

template<class T>
class RBTNode
{
public:
	T key; //键值
	RBTColor color; //颜色
	RBTNode* left; //左孩子
	RBTNode* right; //右孩子
	RBTNode* parent; //父节点

	//构造函数
	RBTNode(T value, RBTColor c, RBTNode* l, RBTNode* r, RBTNode* p) :key(value), color(c), left(l), right(r), parent(p)
	{

	}
};

template<class T>
class RBTree
{
public:
	RBTree();
	~RBTree();
	//销毁自身
	void destroy();
	//将结点（key为节点）
	void insert(T key);
	// 中序遍历"红黑树"
	void inOrder();
	// 打印红黑树
	void print();
	// (递归实现)查找"红黑树"中键值为key的节点
	RBTNode<T>* search(T key);
	// (非递归实现)查找"红黑树"中键值为key的节点
	RBTNode<T>* iterativeSearch(T key);
	// 查找最小结点：返回最小结点的键值。
	T minimum();
	// 查找最大结点：返回最大结点的键值。
	T maximum();
	// 删除结点(key为节点键值)
	void remove(T key);

private:
	//以节点销毁
	void destroy(RBTNode<T>*& tree);
	//从某个节点插入某个节点
	void insert(RBTNode<T>*& root, RBTNode<T>* node);
	//修正函数，将二叉搜索树修正为红黑树
	void insertFixUp(RBTNode<T>*& root, RBTNode<T>* node);
	//左旋
	//root 树的根节点， x 支点
	void leftRotate(RBTNode<T>*& root, RBTNode<T>* x);
	//右旋
	//root 树的根节点， x 支点
	void rightRotate(RBTNode<T>*& root, RBTNode<T>* x);
	// 中序遍历"红黑树"
	void inOrder(RBTNode<T>* root) const;
	// 打印红黑树
	void print(RBTNode<T>* root, T key, int direction);
	// (递归实现)查找"红黑树x"中键值为key的节点
	RBTNode<T>* search(RBTNode<T>* x, T key) const;
	// (非递归实现)查找"红黑树x"中键值为key的节点
	RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;
	// 查找最小结点：返回tree为根结点的红黑树的最小结点。
	RBTNode<T>* minimum(RBTNode<T>* tree);
	// 查找最大结点：返回tree为根结点的红黑树的最大结点。
	RBTNode<T>* maximum(RBTNode<T>* tree);
	// 删除函数
	void remove(RBTNode<T>* &root, RBTNode<T> *node);
	// 删除修正函数
	void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);

private:
	RBTNode<T>* mRoot; //根节点
};
template<class T>
RBTree<T>::RBTree()
{
	mRoot = NULL;
}

template<class T>
RBTree<T>::~RBTree()
{
	destroy();
}

template<class T>
void RBTree<T>::destroy()
{
	destroy(mRoot);
}

template<class T>
void RBTree<T>::destroy(RBTNode<T>*& tree)
{
	if (tree == NULL)
	{
		return;
	}
	if (tree->left != NULL)
	{
		destroy(tree->left);
	}
	if (tree->right != NULL)
	{
		destroy(tree->right);
	}

	delete tree;
	tree = NULL;
}

template<class T>
void RBTree<T>::insert(T key)
{
	RBTNode<T>* z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL);
	insert(mRoot, z);
}

template<class T>
void RBTree<T>::insert(RBTNode<T>*& root, RBTNode<T>* node)
{
	//记录父亲节点
	RBTNode<T>* pMoveParent = NULL;
	//移动指针
	RBTNode<T>* pMove = root;

	//1.将红黑树当做一颗二叉查找树进行插入
	while (pMove != NULL)
	{
		pMoveParent = pMove;
		if (node->key < pMove->key) //如果插入的key小于当前节点的key
		{
			pMove = pMove->left;
		}
		else
		{
			pMove = pMove->right;
		}
	}
	node->parent = pMoveParent;
	if (pMoveParent != NULL)
	{
		if (node->key < pMoveParent->key)
		{
			pMoveParent->left = node;
		}
		else
		{
			pMoveParent->right = node;
		}
	}
	else  //空树
	{
		root = node;
	}

	//2.将新插入的节点的颜色定义为红色
	node->color = RED;

	//3.修正为红黑树
	insertFixUp(root, node);
}

template<class T>
void RBTree<T>::insertFixUp(RBTNode<T>*& root, RBTNode<T>* node)
{
	RBTNode<T>* parent = NULL; //循环过程中的父节点
	RBTNode<T>* gparent = NULL; //循环过程中的祖父节点

	//父节点存在，不存在直接涂黑，并且父节点的颜色是红色, 这个循环里面只考虑情况3、4、5
	while ((parent = node->parent) && parent->color == RED)
	{
		gparent = parent->parent;

		//由于不知道叔叔节点是祖父节点的左孩子还是右孩子，先要判断父节点是祖父节点的左孩子还是右孩子
		//如果 父节点 是 祖父节点 的左孩子,此时叔叔节点是祖父节点的右孩子
		if (parent == gparent->left)
		{
			//首先排除情况3,为了看得更清楚写到代码块
			{
				RBTNode<T>* uncle = gparent->right;
				if (uncle && uncle->color == RED) //如果uncle不是null并且为红色，如果是null一定是黑色，对应情况4或者5
				{
					//父节点和叔叔节点涂黑，祖父节点涂红
					parent->color = BLACK;
					uncle->color = BLACK;
					gparent->color = RED;
					node = gparent; //以祖父节点作为新的插入节点
					continue;
				}
			}
			//如果是父节点的右孩子，对应 情况4
			if (parent->right == node) 
			{
				leftRotate(root, parent); //以父节点为支点左旋
				//父节点和当前节点互换身份，继续
				RBTNode<T>* temp = parent;
				parent = node;
				node = temp;
			}

			//情况5
			parent->color = BLACK; //父节点涂黑
			gparent->color = RED; //祖父节点涂红
			rightRotate(root, gparent); //以祖父节点右旋
		}
		else  		//如果 父节点 是 祖父节点 的右孩子,此时叔叔节点是祖父节点的左孩子
		{
			//首先排除情况3,为了看得更清楚写到代码块
			{
				RBTNode<T>* uncle = gparent->left;
				if (uncle && uncle->color == RED) //如果uncle不是null并且为红色，如果是null一定是黑色，对应情况4或者5
				{
					//父节点和叔叔节点涂黑，祖父节点涂红
					parent->color = BLACK;
					uncle->color = BLACK;
					gparent->color = RED;
					node = gparent; //以祖父节点作为新的插入节点
					continue;
				}
			}

			//如果是父节点的左孩子，对应 情况5
			if (parent->left == node)
			{
				rightRotate(root, parent); //以父节点为支点右旋
				//父节点和当前节点互换身份，继续
				RBTNode<T>* temp = parent;
				parent = node;
				node = temp;
			}

			//情况4
			parent->color = BLACK; //父节点涂黑
			gparent->color = RED; //祖父节点涂红
			leftRotate(root, gparent); //以祖父节点右旋
		}
	}

	// 最后将根节点涂黑
	root->color = BLACK;
}

template<class T>
void RBTree<T>::leftRotate(RBTNode<T>*& root, RBTNode<T>* x)
{
	RBTNode<T>* y = x->right;
	
	//1.将β与x的右节点连接
	//将y的左孩子（β）设为x的右孩子
	x->right = y->left;
	//如果y的左孩子（β）非空，将β的父节点设为x
	if (y->left != NULL)
	{
		y->left->parent = x;
	}

	//2.整体连接
	//如果x的父节点为空，将y设为root根节点
	if (x->parent == NULL)
	{
		root = y;
		y->parent = NULL;
	}
	else //x的父节点不为空
	{
		if (x->parent->left == x)//如果x是它的父节点的左节点，将y设为x的父节点的左节点
		{
			x->parent->left = y;
		}
		else //如果x是它的父节点的右节点，将y设为x的父节点的右节点
		{
			x->parent->right = y;
		}
		y->parent = x->parent;
	}

	//3.x与y连接
	y->left = x;
	x->parent = y;
}

template<class T>
void RBTree<T>::rightRotate(RBTNode<T>*& root, RBTNode<T>* x)
{
	RBTNode<T>* y = x->left;

	//1.将y的右节点（β）与x的左节点连接
	x->left = y->right;
	if (y->right != NULL)
	{
		x->right->parent = x;
	}

	//2.整体连接
	//如果x的父节点为空，将y设为root根节点
	if (x->parent == NULL)
	{
		root = y;
		y->parent = NULL;
	}
	else //x的父节点不为空
	{
		if (x->parent->left == x)//如果x是它的父节点的左节点，将y设为x的父节点的左节点
		{
			x->parent->left = y;
		}
		else //如果x是它的父节点的右节点，将y设为x的父节点的右节点
		{
			x->parent->right = y;
		}
		y->parent = x->parent;
	}

	//3.x与y连接
	y->right = x;
	x->parent = y;
}

template<class T>
void RBTree<T>::inOrder()
{
	inOrder(mRoot);
}

template<class T>
void RBTree<T>::inOrder(RBTNode<T>* root) const
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->key << endl;
		inOrder(root->right);
	}
}


template<class T>
void RBTree<T>::print()
{
	if (mRoot != NULL)
	{
		print(mRoot, mRoot->key, 0);
	}
}

//************************************
// Method:    print
// FullName:  RBTree<T>::print
// Access:    private 
// Returns:   void
// Qualifier:
// Parameter: RBTNode<T> * root 根节点
// Parameter: T key 父节点的键值（根节点是自己的键值）
// Parameter: int direction 0-表示该节点是根节点，1-表示该节点是左节点，2-表示该节点是右节点
//************************************
template<class T>
void RBTree<T>::print(RBTNode<T>* root, T key, int direction)
{
	if (root != NULL)
	{
		print(root->left, root->key, -1);
		if (direction == 0)
		{
			cout << setw(2) << root->key << "(B) is a root" << endl; //setw设置输出宽度
		}
		else
		{
			cout << setw(2) << root->key << ((root->color == RED) ? "(R)" : "(B)") << " is " << setw(2) << key << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;
		}
		print(root->right, root->key, 1);
	}
}


template<class T>
RBTNode<T>* RBTree<T>::search(T key)
{
	return search(mRoot, key);
}


template<class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, T key) const
{
	if (x == NULL || x->key == key)
	{
		return x;
	}

	if (key < x->key)
	{
		search(x->left, key);
	}
	else
	{
		search(x->right, key);
	}
}


template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
	return iterativeSearch(mRoot, key);
}


template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key) const
{
	while (x != NULL && x->key != key)
	{
		if (key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
}


template<class T>
T RBTree<T>::minimum()
{
	RBTNode<T>* p = minimum(mRoot);
	if (p != NULL)
	{
		return p->key;
	}
	return (T)NULL;
}


template<class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* tree)
{
	if (tree == NULL)
	{
		return NULL;
	}

	while (tree->left != NULL)
	{
		tree = tree->left;
	}
	return tree;
}


template<class T>
T RBTree<T>::maximum()
{
	RBTNode<T>* p = maximum(mRoot);
	if (p != NULL)
	{
		return p->key;
	}
	return (T)NULL;
}


template<class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree)
{
	if (tree == NULL)
	{
		return NULL;
	}

	while (tree->right != NULL)
	{
		tree = tree->right;
	}
	return tree;
}


template<class T>
void RBTree<T>::remove(T key)
{
	//先找到，找到的话就删除
	RBTNode<T>* node;
	if ((node = search(mRoot, key)) != NULL)
	{
		remove(mRoot, node);
	}
}


template<class T>
void RBTree<T>::remove(RBTNode<T>*& root, RBTNode<T> *node)
{
	RBTNode<T>* child;
	RBTNode<T>* parent;
	RBTColor color;
	if ((node->left != NULL) && (node->right != NULL))
	{
		//先找到替代节点
		RBTNode<T>* replace = node;
		replace = replace->right;
		while (replace->left != NULL) 
		{
			replace = replace->left;
		}

		if (node->parent != NULL) //如果不是根节点
		{
			if (node == node->parent->left)   //如果node是左节点
			{
				node->parent->left = replace;
			}
			else   //如果node是右节点
			{
				node->parent->right = replace;
			}
		}
		else   //如果是根节点
		{
			root = replace;
		}

		child = replace->right;
		parent = replace->parent;
		color = replace->color;

		if (parent == node)  //如果被删节点是“替代节点”的父节点
		{
			parent = replace;  //这句话必须要，用于修正函数传参
		}
		else   //如果被删节点不是“替代节点”的父节点
		{
			if (child)
			{
				child->parent = parent;
			}
			parent->left = child;

			replace->right = node->right;
			node->right->parent = replace;
		}

		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;

		if (color == BLACK)
		{
			//root-根节点，child-替代节点的孩子节点，parent-“替代节点”的父节点 或者 "替代节点"本身
			removeFixUp(root, child, parent);
		}

		delete node;
		return;
	}
	
	if (node->left != NULL)
	{
		child = node->left;
	}
	else
	{
		child = node->right;
	}

	parent = node->parent;
	color = node->color;   //保存待删除节点颜色

	if (child)
	{
		child->parent = parent;
	}

	if (parent)   //如果不是根节点
	{
		if (node == parent->left)  //如果当前节点是左节点
		{
			parent->left = child;
		}
		else
		{
			parent->right = child;
		}
	}
	else
	{
		root = child;
	}

	if (color == BLACK)
	{
		//root-根节点， child-删除节点的孩子节点， parent-删除节点的父节点
		this->removeFixUp(root, child, parent);
	}
}


//************************************
// Method:    removeFixUp 删除修正函数
// FullName:  RBTree<T>::removeFixUp
// Access:    private 
// Returns:   void
// Qualifier:
// Parameter: RBTNode<T> *  & root 根节点
// Parameter: RBTNode<T> * node 删除节点（或者替代节点）的孩子节点，可能为NULL
// Parameter: RBTNode<T> * parent  删除节点（或者“替代节点”的父节点 或者 "替代节点"本身点）的父节点，可能为NULL
//************************************
template<class T>
void RBTree<T>::removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent)
{
	RBTNode<T> *other;
	//当node是不是根节点 并且 （node是NULL时，不论颜色是什么；node不是NULL，颜色是黑色）时，一直循环。
	//也就是，从下往上（可能从NULL往上）推到红色节点时停止（循环里面的node一直是黑色），一直找到根节点
	while ((!node || node->color == BLACK) && node != root) 
	{
		if (parent->left == node)  //node是左节点
		{
			//兄弟节点
			other = parent->right;
			if (other->color == RED)
			{
				// Case 1: x(node)的兄弟w（other）是红色的
				other->color = BLACK;
				parent->color = RED;
				leftRotate(root, parent);
				other = parent->right;
			}
			if ((!other->left || other->left->color == BLACK) &&
				(!other->right || other->right->color == BLACK))
			{
				// Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的
				other->color = RED;
				node = parent;
				parent = node->parent;
			}
			else
			{
				if (!other->right || other->right->color == BLACK)
				{
					// Case 3: x的兄弟w是黑色的，并且w的右孩子是黑色，左孩子为红色。
					other->left->color = BLACK;
					other->color = RED;
					rightRotate(root, other);
					other = parent->right;
				}
				// Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
				other->color = parent->color;
				parent->color = BLACK;
				other->right->color = BLACK;
				leftRotate(root, parent);
				node = root;
				break;
			}
		}
		else   //node是右节点
		{
			other = parent->left;
			if (other->color == RED)
			{
				// Case 1: x的兄弟w是红色的
				other->color = BLACK;
				parent->color = RED;
				rightRotate(root, parent);
				other = parent->left;
			}
			if ((!other->left || other->left->color == BLACK) &&
				(!other->right || other->right->color == BLACK))
			{
				// Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的
				other->color = RED;
				node = parent;
				parent = node->parent;
			}
			else
			{
				if (!other->left || other->left->color == BLACK)
				{
					// Case 3: x的兄弟w是黑色的，并且w的左孩子是黑色，右孩子为红色。
					other->right->color = BLACK;
					other->color = RED;
					leftRotate(root, other);
					other = parent->left;
				}
				// Case 4: x的兄弟w是黑色的；并且w的左孩子是红色，右孩子任意颜色。
				other->color = parent->color;
				parent->color = RED;
				other->left->color = BLACK;
				rightRotate(root, parent);
				node = root;
				break;
			}
		}
	}
	if (node)
		node->color = BLACK;
}
#endif // _RED_BLACK_TREE_HPP