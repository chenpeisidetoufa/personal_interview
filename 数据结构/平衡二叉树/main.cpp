//平衡二叉树为搜索而生，为了更快的查找，损失了插入和删除的效率
//属于有序二叉树
//左右子树高度差不超过1
//如何保持二叉树平衡，旋转！！！
//在插入和删除操作进行的时候，会出现不平衡
//只有四种情况出现不平衡
//			○10				○9										○12					○8
//		○8 轴						○11 轴							○8	轴							○12 轴
//	○6									○18							○10					○10
//
//		右旋						左旋							左右旋						右左旋
//
//		○8							○11								○12					○8	
//	○6		○10				○9		○18						○10轴							○10轴
//																○8										○12
//
//																	右旋							左旋
//																	○10							○10
//																○8		○12					○8		○12

//

#include <iostream>
#include "AVLTree.h"
using namespace std;

int main()
{
	AVLTree<int> tree; //高度0
	tree.insert(40); //高度1
	tree.insert(30); //高度2
	tree.insert(60); //高度2
	tree.insert(50); //高度3
	tree.insert(80); //高度3
	tree.insert(70); //高度4，此时有旋转，具体各节点高度（60-4 ×、40-3 ×、30-1、50-1、80-2、70-1）与实际不相符，但是在下次插入会把相关路径上不正确的高度修正
	//tree.insert(90); //高度4，具体各节点高度（60-4 ×、40-3 ×、30-1、50-1、80-2、70-1、90-1）与实际不相符,没有把错误的高度修正
	//tree.insert(20); //高度4，修正了高度，与实际相符，需要先把子节点的高度修正，再修复上层节点
	tree.insert(65); //高度4，此时有旋转，具体各节点高度（60-4 ×、40-3 ×、30-1、50-1、70-3 ×、65-1、80-2）与实际不相符,没有把错误的高度修正，并且新加了错误高度
	return 0;
}