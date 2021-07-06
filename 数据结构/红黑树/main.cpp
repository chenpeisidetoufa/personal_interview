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

	//�������
	cout << "������������" << endl;
	tree->inOrder();
	cout << endl;

	//��ӡ��
	cout << "��ӡ����" << endl;
	tree->print();
	cout << endl;

	//������
	int s = 60;
	cout << "����" << s << "�����" << endl;
	RBTNode<int>* temp = tree->search(s);
	if (temp == NULL)
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "�Ѳ鵽��" << temp->key << endl;
	}
	cout << endl;
	
	//�����Сֵ
	cout << "��Сֵ��" << tree->minimum() << endl;
	cout << "���ֵ��" << tree->maximum() << endl;

	tree->destroy();

	return 0;
}