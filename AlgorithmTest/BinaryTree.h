#pragma once

#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_nvalue;

	BinaryTreeNode * m_pLeft;
	BinaryTreeNode * m_pRight;
};

BinaryTreeNode * Construct(int *preorder, int *inorder, int length);

BinaryTreeNode * ConstructCore(int *startPerorder, int *endPerorder, int *startInorder, int *endInorder);

void PerOrder(BinaryTreeNode *root);

void BinaryTest();