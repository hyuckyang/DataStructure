#include "DoubleLinkedList.h"

template <typename T>
DoubleLinkedNode<T>::DoubleLinkedNode()
{
	pHead = nullptr;
	pTail = nullptr;
}


template <typename T>
DoubleLinkedNode<T>::DoubleLinkedNode(T data)
{
	this->data = data;
	pHead = nullptr;
	pTail = nullptr;
}


template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(void (*print)(DoubleLinkedNode<T>* head, bool reverse))
{
	this->print = print;
	pHead = nullptr;
}

template <typename T>
void DoubleLinkedList<T>::Insert(T data)
{
	DoubleLinkedNode<T>* node = new DoubleLinkedNode<T>(data);
	if(pHead == nullptr)
	{
		pHead = node;
	}
	else
	{
		DoubleLinkedNode<T>* pNode = pHead;
		node->SetTail(pNode);
		pNode->SetHead(node);
		pHead = node;
	}
}

template <typename T>
void DoubleLinkedList<T>::Add(T data)
{
	DoubleLinkedNode<T>* node = new DoubleLinkedNode<T>(data);
	if (pHead == nullptr)
	{
		pHead = node;
	}
	else
	{
		DoubleLinkedNode<T>* pNode = pHead;
		while (pNode->GetTail() != nullptr)
			pNode = pNode->GetTail();

		pNode->SetTail(node);
		node->SetHead(pNode);
	}
}

template <typename T>
void DoubleLinkedList<T>::Remove()
{
	int length = GetLength();
	if (length <= 0)
		return;

	RemoveAt(length - 1);
}



template <typename T>
void DoubleLinkedList<T>::RemoveAt(int index)
{
	DoubleLinkedNode<T>* pNode = pHead;
	int count = 0;
	while (pNode != nullptr)
	{
		if (index == count)
			break;

		count++;
		pNode = pNode->GetTail();
	}

	if (pNode == nullptr)
		return;

	DoubleLinkedNode<T>* head = pNode->GetHead();
	DoubleLinkedNode<T>* tail = pNode->GetTail();

	if (head != nullptr)
		head->SetTail(tail);

	if (tail != nullptr)
		tail->SetHead(head);

	if (pHead == pNode)
		pHead = nullptr;
	
	delete(pNode);
}



template <typename T>
int DoubleLinkedList<T>::GetLength()
{
	DoubleLinkedNode<T>* pNode = pHead;
	int length = 0;
	while (pNode != nullptr)
	{
		length++;
		pNode = pNode->GetTail();
	}

	return length;
}

template <typename T>
void DoubleLinkedList<T>::Print(bool reverse)
{
	if (print != nullptr)
		print(pHead, reverse);
}

