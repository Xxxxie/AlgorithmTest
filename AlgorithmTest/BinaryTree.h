#pragma once

#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_nvalue;

	BinaryTreeNode * m_pLeft;
	BinaryTreeNode * m_pRight;
	BinaryTreeNode * m_pParent;
};

BinaryTreeNode * Construct(int *preorder, int *inorder, int length);

BinaryTreeNode * ConstructCore(int *startPerorder, int *endPerorder, int *startInorder, int *endInorder);

//中序遍历的下一节点
BinaryTreeNode * GetNext(BinaryTreeNode *node);

void PerOrder(BinaryTreeNode *root);

void BinaryTest();