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

	// 전위 순회 == root -> left -> right;
	void PreOrder();

	// 중위 순회 == left -> root -> right;
	void InOrder();

	// 후위 순위 == left -> right -> root;
	void PostOrder();

	//void InOrderIter(T data);
};