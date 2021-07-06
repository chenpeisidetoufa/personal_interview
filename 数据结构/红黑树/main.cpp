#include "RBTree.h"

int main()
{
	RBTree<int>* tree = new RBTree<int>();
	tree->insert(30);
	tree->insert(20);
	tree->insert(50);
	tree->insert(60);
	tree->insert(10);
	tree->insert(25);
	tree->insert(55);
	tree->insert(26);

	tree->remove(55);

	//中序遍历
	cout << "中序遍历结果：" << endl;
	tree->inOrder();
	cout << endl;

	//打印树
	cout << "打印树：" << endl;
	tree->print();
	cout << endl;

	//查找树
	int s = 60;
	cout << "查找" << s << "结果：" << endl;
	RBTNode<int>* temp = tree->search(s);
	if (temp == NULL)
	{
		cout << "空树" << endl;
	}
	else
	{
		cout << "已查到：" << temp->key << endl;
	}
	cout << endl;
	
	//最大最小值
	cout << "最小值：" << tree->minimum() << endl;
	cout << "最大值：" << tree->maximum() << endl;

	tree->destroy();

	return 0;
}