#include "BinaryTree.h"


template <typename T>
BTreeNode<T>::BTreeNode(T data)
{
	this->data = data;
	left = nullptr;
	right = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(void (*print)(T data), BTreeNode<T>* root)
{
	this->print = print;
	pRoot = root;
}

template <typename T>
void BinaryTree<T>::PreOrder()
{
	if (print == nullptr)
		return;
	
	PreOrderPrint(pRoot);
}

template <typename T>
void BinaryTree<T>::PreOrderPrint(BTreeNode<T>* node)
{
	if (node == nullptr)
		return;

	print(node->GetData());
	PreOrderPrint(node->GetLeft());
	PreOrderPrint(node->GetRight());
}

template <typename T>
void BinaryTree<T>::InOrder()
{
	if (print == nullptr)
		return;

	InOrderPrint(pRoot);
}

template <typename T>
void BinaryTree<T>::InOrderPrint(BTreeNode<T>* node)
{
	if (node == nullptr)
		return;
	
	InOrderPrint(node->GetLeft());
	print(node->GetData());
	InOrderPrint(node->GetRight());
}

template <typename T>
void BinaryTree<T>::PostOrder()
{
	if (print == nullptr)
		return;

	PostOrderPrint(pRoot);
}

template <typename T>
void BinaryTree<T>::PostOrderPrint(BTreeNode<T>* node)
{
	if (node == nullptr)
		return;
	
	PostOrderPrint(node->GetLeft());
	PostOrderPrint(node->GetRight());
	print(node->GetData());
}

//template <typename T>
//void BinaryTree<T>::InOrderIter(T data)
//{
//	auto node = new BTreeNode<T>(data);
//	if (pRoot == nullptr)
//	{
//		pRoot = node;
//		return;
//	}
//	
//	auto pNode = pRoot;
//	while (true)
//	{
//		
//	}
//
//}

