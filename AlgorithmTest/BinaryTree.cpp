#include "BinaryTree.h"

using namespace std;

//前序遍历二叉树
void PerOrder(BinaryTreeNode *root)
{
	if (root == nullptr)
	{
		return ;
	}

	cout << root->m_nvalue << endl;
	PerOrder(root->m_pLeft);
	PerOrder(root->m_pRight);
}


//由中序和前序构建二叉树
BinaryTreeNode * Construct(int *preorder, int *inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return  nullptr;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode * ConstructCore(int *startPerorder, int *endPerorder, int *startInorder, int *endInorder)
{
	
	int rootvalue = startPerorder[0];
	BinaryTreeNode * root = new BinaryTreeNode();
	root->m_nvalue = rootvalue;
	root->m_pLeft = nullptr;
	root->m_pRight = nullptr;
	if (startPerorder == endPerorder )
	{
		if (*startInorder == *startPerorder)
			return root;
		else
			throw exception("Invaild value");

	}

	int * rootInorder = startInorder;
	
	while ( rootInorder <endInorder && *rootInorder != rootvalue)
	{
		rootInorder++;
	
	}

	if (rootInorder == endInorder && *rootInorder!=rootvalue)
	{
		throw exception("Invaild value");
	}

	int leftLength = rootInorder - startInorder;

	int * leftPreorderEnd = startPerorder + leftLength;

	if (leftLength > 0)
	{
		root->m_pLeft = ConstructCore(startPerorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPerorder - startPerorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPerorder, rootInorder + 1, endInorder);
	}


	return root;
}


void BinaryTest()
{
	int a[8] = { 1,2,4,7,3,5,6,8 };
	int b[8] = { 4,7,2,1,5,3,8,6 };
	BinaryTreeNode* root = Construct(a, b, 8);

	PerOrder(root);

}