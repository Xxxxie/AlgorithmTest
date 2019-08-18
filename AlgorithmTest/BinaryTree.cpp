#include "BinaryTree.h"

using namespace std;

//ǰ�����������
void PerOrder(BinaryTreeNode *root)
{
	if (root == nullptr)
	{
		return ;
	}

	cout << root->m_nvalue <<" ";
	PerOrder(root->m_pLeft);
	PerOrder(root->m_pRight);
}


//�������ǰ�򹹽�������
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
	root->m_pParent = nullptr;
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
		root->m_pLeft->m_pParent = root;
	}
	if (leftLength < endPerorder - startPerorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPerorder, rootInorder + 1, endInorder);
		root->m_pRight->m_pParent = root;
	}


	return root;
}
/*********************************************
*������������next�ڵ�
*1.����ڵ���ҽڵ㲻Ϊ�գ���next�ڵ�Ϊ������������ڵ�
*2.����鿴�ڵ�ĸ����
*3.����ڵ�Ϊ��������ڵ㣬��next�ڵ�Ϊ�����
*4.����Ѱ�Ҹ����ĸ���㣬ֱ��Ѱ�ҵ�Ϊ��ڵ�ĸ����node����nextΪnode�ĸ����
*******************************************/
BinaryTreeNode *GetNext(BinaryTreeNode *node)
{

	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->m_pRight != nullptr)
	{
		BinaryTreeNode *pT = node->m_pRight;
		while (pT->m_pLeft!=nullptr)
		{
			pT = pT->m_pLeft;
		}
		return pT;
	}
	else if(node->m_pParent = nullptr)
	{
		BinaryTreeNode * parent = node->m_pParent;
		if (parent->m_pLeft == node)
		{
			return parent;
		}

		if (parent->m_pRight == node)
		{
			BinaryTreeNode * temp = parent->m_pParent;

			while (temp != nullptr && parent != temp->m_pLeft)
			{
				parent = temp;
				temp = parent->m_pParent;
			}
			return temp;

		}
	}

	return nullptr;


}

void BinaryTest()
{
	int a[8] = { 1,2,4,7,3,5,6,8 };
	int b[8] = { 4,7,2,1,5,3,8,6 };
	BinaryTreeNode* root = Construct(a, b, 8);

	PerOrder(root);
	cout << endl;

	BinaryTreeNode* next = GetNext(root);
	cout << next->m_nvalue << endl;


}