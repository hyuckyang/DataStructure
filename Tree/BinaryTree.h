#pragma once

template <typename T>
class BTreeNode
{
	T data;
	BTreeNode* left, * right;
public:

	BTreeNode(T data);

	T GetData() { return data; }

	void SetLeft(BTreeNode* node) { left = node; }
	BTreeNode* GetLeft() { return left; }
	void SetRight(BTreeNode* node) { right = node; }
	BTreeNode* GetRight() { return right; }
};

template <typename T>
class BinaryTree
{
	void (*print)(T data);
	BTreeNode<T>* pRoot;

	void PreOrderPrint(BTreeNode<T>* node);
	void InOrderPrint(BTreeNode<T>* node);
	void PostOrderPrint(BTreeNode<T>* node);



public:
	BinaryTree(void (*print)(T data), BTreeNode<T>* root);

	// ���� ��ȸ == root -> left -> right;
	void PreOrder();

	// ���� ��ȸ == left -> root -> right;
	void InOrder();

	// ���� ���� == left -> right -> root;
	void PostOrder();

	//void InOrderIter(T data);
};