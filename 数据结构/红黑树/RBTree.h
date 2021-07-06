//���ԣ�
//��1��ÿ���ڵ��Ǻ�ɫ�����Ǻ�ɫ
//��2�����ڵ��Ǻ�ɫ
//��2��ÿ��Ҷ�ӽڵ㣨NULL���Ǻ�˿
//��3�����һ���ڵ��Ǻ�ɫ���������ӽڵ�����Ǻ�ɫ
//��5����һ���ڵ㵽�ýڵ������ڵ������·���ϰ�����ͬ��Ŀ�ĺڽڵ㣬������ȷ����û��һ��·���������·��������������ˣ����������Խӽ�ƽ��Ķ�����

/*
 * ������
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(����)-->           / \                
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */

 /*
  * ������
  *            py                               py
  *           /                                /
  *          y                                x
  *         /  \      --(����)-->            /  \                    
  *        x   ry                           lx   y
  *       / \                                   / \                 
  *      lx  rx                                rx  ry
  *
  */

  //���������
  //Ϊ���������ԣ�5���������ʱ������Ĭ���Ƚ�����ڵ�Ϳ��
  //���1��������ڵ㣬ԭ���ǿ�����Ϳ�ڼ���
  //���2�������Ľڵ�ĸ��ڵ��Ǻ�ɫ�ģ�ʲô��������
  //���3�������ĸ��ڵ��Ǻ�ɫ�ģ���������ڵ�Ҳ�Ǻ�ɫ--------�Բߣ�����ǰ�ڵ�ĸ��ڵ������ڵ�Ϳ�ڣ��游�ڵ�Ϳ��,�����游�ڵ����ѭ��
  //���4����ǰ�ڵ�ĸ��ڵ��Ǻ�ɫ������ڵ��Ǻ�ɫ����ǰ�ڵ����丸�ڵ�����ӽڵ�
  //       �Բߣ�1�����ڵ����游�ڵ����ڵ㣺1.�Ը��ڵ���Ϊ֧��������2.���Ը��ڵ����----------�������Ϊ���5
  //             2�����ڵ����游�ڵ���ҽڵ㣺1.���ڵ�Ϳ�ڣ�2.�游�ڵ�Ϳ�죻3.���游�ڵ�Ϊ֧��������4.�ڵ㱣�ֲ������ѭ��
  //���5����ǰ�ڵ�ĸ��ڵ��Ǻ�ɫ������ڵ��Ǻ�ɫ����ǰ�ڵ����丸�ڵ�����ӽڵ�
  //       �Բߣ�1�����ڵ����游�ڵ����ڵ㣺1.���ڵ�Ϳ�ڣ�2.�游�ڵ�Ϳ�죻3.���游�ڵ�Ϊ֧��������4.�ڵ㱣�ֲ������ѭ��
  //             2�����ڵ����游�ڵ���ҽڵ㣺1.�Ը��ڵ���Ϊ֧��������2.���Ը��ڵ����----------�������Ϊ���4
  //�ų������3��4��5������ѭ������󽫸��ڵ�Ϳ��


#ifndef _RED_BLACK_TREE_HPP
#define _RED_BLACK_TREE_HPP

#include<iomanip> //I/O������ͷ�ļ�
#include <iostream>
using namespace std;

//��ɫö��
enum RBTColor
{
	RED,
	BLACK
};

template<class T>
class RBTNode
{
public:
	T key; //��ֵ
	RBTColor color; //��ɫ
	RBTNode* left; //����
	RBTNode* right; //�Һ���
	RBTNode* parent; //���ڵ�

	//���캯��
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
	//��������
	void destroy();
	//����㣨keyΪ�ڵ㣩
	void insert(T key);
	// �������"�����"
	void inOrder();
	// ��ӡ�����
	void print();
	// (�ݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
	RBTNode<T>* search(T key);
	// (�ǵݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
	RBTNode<T>* iterativeSearch(T key);
	// ������С��㣺������С���ļ�ֵ��
	T minimum();
	// ��������㣺���������ļ�ֵ��
	T maximum();
	// ɾ�����(keyΪ�ڵ��ֵ)
	void remove(T key);

private:
	//�Խڵ�����
	void destroy(RBTNode<T>*& tree);
	//��ĳ���ڵ����ĳ���ڵ�
	void insert(RBTNode<T>*& root, RBTNode<T>* node);
	//��������������������������Ϊ�����
	void insertFixUp(RBTNode<T>*& root, RBTNode<T>* node);
	//����
	//root ���ĸ��ڵ㣬 x ֧��
	void leftRotate(RBTNode<T>*& root, RBTNode<T>* x);
	//����
	//root ���ĸ��ڵ㣬 x ֧��
	void rightRotate(RBTNode<T>*& root, RBTNode<T>* x);
	// �������"�����"
	void inOrder(RBTNode<T>* root) const;
	// ��ӡ�����
	void print(RBTNode<T>* root, T key, int direction);
	// (�ݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
	RBTNode<T>* search(RBTNode<T>* x, T key) const;
	// (�ǵݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
	RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;
	// ������С��㣺����treeΪ�����ĺ��������С��㡣
	RBTNode<T>* minimum(RBTNode<T>* tree);
	// ��������㣺����treeΪ�����ĺ����������㡣
	RBTNode<T>* maximum(RBTNode<T>* tree);
	// ɾ������
	void remove(RBTNode<T>* &root, RBTNode<T> *node);
	// ɾ����������
	void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);

private:
	RBTNode<T>* mRoot; //���ڵ�
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
	//��¼���׽ڵ�
	RBTNode<T>* pMoveParent = NULL;
	//�ƶ�ָ��
	RBTNode<T>* pMove = root;

	//1.�����������һ�Ŷ�����������в���
	while (pMove != NULL)
	{
		pMoveParent = pMove;
		if (node->key < pMove->key) //��������keyС�ڵ�ǰ�ڵ��key
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
	else  //����
	{
		root = node;
	}

	//2.���²���Ľڵ����ɫ����Ϊ��ɫ
	node->color = RED;

	//3.����Ϊ�����
	insertFixUp(root, node);
}

template<class T>
void RBTree<T>::insertFixUp(RBTNode<T>*& root, RBTNode<T>* node)
{
	RBTNode<T>* parent = NULL; //ѭ�������еĸ��ڵ�
	RBTNode<T>* gparent = NULL; //ѭ�������е��游�ڵ�

	//���ڵ���ڣ�������ֱ��Ϳ�ڣ����Ҹ��ڵ����ɫ�Ǻ�ɫ, ���ѭ������ֻ�������3��4��5
	while ((parent = node->parent) && parent->color == RED)
	{
		gparent = parent->parent;

		//���ڲ�֪������ڵ����游�ڵ�����ӻ����Һ��ӣ���Ҫ�жϸ��ڵ����游�ڵ�����ӻ����Һ���
		//��� ���ڵ� �� �游�ڵ� ������,��ʱ����ڵ����游�ڵ���Һ���
		if (parent == gparent->left)
		{
			//�����ų����3,Ϊ�˿��ø����д�������
			{
				RBTNode<T>* uncle = gparent->right;
				if (uncle && uncle->color == RED) //���uncle����null����Ϊ��ɫ�������nullһ���Ǻ�ɫ����Ӧ���4����5
				{
					//���ڵ������ڵ�Ϳ�ڣ��游�ڵ�Ϳ��
					parent->color = BLACK;
					uncle->color = BLACK;
					gparent->color = RED;
					node = gparent; //���游�ڵ���Ϊ�µĲ���ڵ�
					continue;
				}
			}
			//����Ǹ��ڵ���Һ��ӣ���Ӧ ���4
			if (parent->right == node) 
			{
				leftRotate(root, parent); //�Ը��ڵ�Ϊ֧������
				//���ڵ�͵�ǰ�ڵ㻥����ݣ�����
				RBTNode<T>* temp = parent;
				parent = node;
				node = temp;
			}

			//���5
			parent->color = BLACK; //���ڵ�Ϳ��
			gparent->color = RED; //�游�ڵ�Ϳ��
			rightRotate(root, gparent); //���游�ڵ�����
		}
		else  		//��� ���ڵ� �� �游�ڵ� ���Һ���,��ʱ����ڵ����游�ڵ������
		{
			//�����ų����3,Ϊ�˿��ø����д�������
			{
				RBTNode<T>* uncle = gparent->left;
				if (uncle && uncle->color == RED) //���uncle����null����Ϊ��ɫ�������nullһ���Ǻ�ɫ����Ӧ���4����5
				{
					//���ڵ������ڵ�Ϳ�ڣ��游�ڵ�Ϳ��
					parent->color = BLACK;
					uncle->color = BLACK;
					gparent->color = RED;
					node = gparent; //���游�ڵ���Ϊ�µĲ���ڵ�
					continue;
				}
			}

			//����Ǹ��ڵ�����ӣ���Ӧ ���5
			if (parent->left == node)
			{
				rightRotate(root, parent); //�Ը��ڵ�Ϊ֧������
				//���ڵ�͵�ǰ�ڵ㻥����ݣ�����
				RBTNode<T>* temp = parent;
				parent = node;
				node = temp;
			}

			//���4
			parent->color = BLACK; //���ڵ�Ϳ��
			gparent->color = RED; //�游�ڵ�Ϳ��
			leftRotate(root, gparent); //���游�ڵ�����
		}
	}

	// ��󽫸��ڵ�Ϳ��
	root->color = BLACK;
}

template<class T>
void RBTree<T>::leftRotate(RBTNode<T>*& root, RBTNode<T>* x)
{
	RBTNode<T>* y = x->right;
	
	//1.������x���ҽڵ�����
	//��y�����ӣ��£���Ϊx���Һ���
	x->right = y->left;
	//���y�����ӣ��£��ǿգ����µĸ��ڵ���Ϊx
	if (y->left != NULL)
	{
		y->left->parent = x;
	}

	//2.��������
	//���x�ĸ��ڵ�Ϊ�գ���y��Ϊroot���ڵ�
	if (x->parent == NULL)
	{
		root = y;
		y->parent = NULL;
	}
	else //x�ĸ��ڵ㲻Ϊ��
	{
		if (x->parent->left == x)//���x�����ĸ��ڵ����ڵ㣬��y��Ϊx�ĸ��ڵ����ڵ�
		{
			x->parent->left = y;
		}
		else //���x�����ĸ��ڵ���ҽڵ㣬��y��Ϊx�ĸ��ڵ���ҽڵ�
		{
			x->parent->right = y;
		}
		y->parent = x->parent;
	}

	//3.x��y����
	y->left = x;
	x->parent = y;
}

template<class T>
void RBTree<T>::rightRotate(RBTNode<T>*& root, RBTNode<T>* x)
{
	RBTNode<T>* y = x->left;

	//1.��y���ҽڵ㣨�£���x����ڵ�����
	x->left = y->right;
	if (y->right != NULL)
	{
		x->right->parent = x;
	}

	//2.��������
	//���x�ĸ��ڵ�Ϊ�գ���y��Ϊroot���ڵ�
	if (x->parent == NULL)
	{
		root = y;
		y->parent = NULL;
	}
	else //x�ĸ��ڵ㲻Ϊ��
	{
		if (x->parent->left == x)//���x�����ĸ��ڵ����ڵ㣬��y��Ϊx�ĸ��ڵ����ڵ�
		{
			x->parent->left = y;
		}
		else //���x�����ĸ��ڵ���ҽڵ㣬��y��Ϊx�ĸ��ڵ���ҽڵ�
		{
			x->parent->right = y;
		}
		y->parent = x->parent;
	}

	//3.x��y����
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
// Parameter: RBTNode<T> * root ���ڵ�
// Parameter: T key ���ڵ�ļ�ֵ�����ڵ����Լ��ļ�ֵ��
// Parameter: int direction 0-��ʾ�ýڵ��Ǹ��ڵ㣬1-��ʾ�ýڵ�����ڵ㣬2-��ʾ�ýڵ����ҽڵ�
//************************************
template<class T>
void RBTree<T>::print(RBTNode<T>* root, T key, int direction)
{
	if (root != NULL)
	{
		print(root->left, root->key, -1);
		if (direction == 0)
		{
			cout << setw(2) << root->key << "(B) is a root" << endl; //setw����������
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
	//���ҵ����ҵ��Ļ���ɾ��
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
		//���ҵ�����ڵ�
		RBTNode<T>* replace = node;
		replace = replace->right;
		while (replace->left != NULL) 
		{
			replace = replace->left;
		}

		if (node->parent != NULL) //������Ǹ��ڵ�
		{
			if (node == node->parent->left)   //���node����ڵ�
			{
				node->parent->left = replace;
			}
			else   //���node���ҽڵ�
			{
				node->parent->right = replace;
			}
		}
		else   //����Ǹ��ڵ�
		{
			root = replace;
		}

		child = replace->right;
		parent = replace->parent;
		color = replace->color;

		if (parent == node)  //�����ɾ�ڵ��ǡ�����ڵ㡱�ĸ��ڵ�
		{
			parent = replace;  //��仰����Ҫ������������������
		}
		else   //�����ɾ�ڵ㲻�ǡ�����ڵ㡱�ĸ��ڵ�
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
			//root-���ڵ㣬child-����ڵ�ĺ��ӽڵ㣬parent-������ڵ㡱�ĸ��ڵ� ���� "����ڵ�"����
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
	color = node->color;   //�����ɾ���ڵ���ɫ

	if (child)
	{
		child->parent = parent;
	}

	if (parent)   //������Ǹ��ڵ�
	{
		if (node == parent->left)  //�����ǰ�ڵ�����ڵ�
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
		//root-���ڵ㣬 child-ɾ���ڵ�ĺ��ӽڵ㣬 parent-ɾ���ڵ�ĸ��ڵ�
		this->removeFixUp(root, child, parent);
	}
}


//************************************
// Method:    removeFixUp ɾ����������
// FullName:  RBTree<T>::removeFixUp
// Access:    private 
// Returns:   void
// Qualifier:
// Parameter: RBTNode<T> *  & root ���ڵ�
// Parameter: RBTNode<T> * node ɾ���ڵ㣨��������ڵ㣩�ĺ��ӽڵ㣬����ΪNULL
// Parameter: RBTNode<T> * parent  ɾ���ڵ㣨���ߡ�����ڵ㡱�ĸ��ڵ� ���� "����ڵ�"����㣩�ĸ��ڵ㣬����ΪNULL
//************************************
template<class T>
void RBTree<T>::removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent)
{
	RBTNode<T> *other;
	//��node�ǲ��Ǹ��ڵ� ���� ��node��NULLʱ��������ɫ��ʲô��node����NULL����ɫ�Ǻ�ɫ��ʱ��һֱѭ����
	//Ҳ���ǣ��������ϣ����ܴ�NULL���ϣ��Ƶ���ɫ�ڵ�ʱֹͣ��ѭ�������nodeһֱ�Ǻ�ɫ����һֱ�ҵ����ڵ�
	while ((!node || node->color == BLACK) && node != root) 
	{
		if (parent->left == node)  //node����ڵ�
		{
			//�ֵܽڵ�
			other = parent->right;
			if (other->color == RED)
			{
				// Case 1: x(node)���ֵ�w��other���Ǻ�ɫ��
				other->color = BLACK;
				parent->color = RED;
				leftRotate(root, parent);
				other = parent->right;
			}
			if ((!other->left || other->left->color == BLACK) &&
				(!other->right || other->right->color == BLACK))
			{
				// Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��
				other->color = RED;
				node = parent;
				parent = node->parent;
			}
			else
			{
				if (!other->right || other->right->color == BLACK)
				{
					// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ������Ϊ��ɫ��
					other->left->color = BLACK;
					other->color = RED;
					rightRotate(root, other);
					other = parent->right;
				}
				// Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
				other->color = parent->color;
				parent->color = BLACK;
				other->right->color = BLACK;
				leftRotate(root, parent);
				node = root;
				break;
			}
		}
		else   //node���ҽڵ�
		{
			other = parent->left;
			if (other->color == RED)
			{
				// Case 1: x���ֵ�w�Ǻ�ɫ��
				other->color = BLACK;
				parent->color = RED;
				rightRotate(root, parent);
				other = parent->left;
			}
			if ((!other->left || other->left->color == BLACK) &&
				(!other->right || other->right->color == BLACK))
			{
				// Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��
				other->color = RED;
				node = parent;
				parent = node->parent;
			}
			else
			{
				if (!other->left || other->left->color == BLACK)
				{
					// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��
					other->right->color = BLACK;
					other->color = RED;
					leftRotate(root, other);
					other = parent->left;
				}
				// Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���������ɫ��
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