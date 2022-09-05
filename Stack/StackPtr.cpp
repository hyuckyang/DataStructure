#include "StackPtr.h"
#include <stdio.h>

template <typename T>
StackPtrNode<T>::StackPtrNode(T data)
{
	this->data = data;
	this->node = nullptr;
}

template <typename T>
StackPtr<T>::StackPtr(void (* print)(T data))
{
	this->pHead = nullptr;
	this->print = print;
}

template <typename T>
void StackPtr<T>::Push(T data)
{
	auto node = new StackPtrNode<T>(data);
	if (pHead == nullptr)
	{
		pHead = node;
	}
	else
	{
		node->SetNode(pHead);
		pHead = node;
	}
}

template <typename T>
void StackPtr<T>::Pop(T& data)
{
	if (pHead == nullptr)
		return;

	auto node = pHead;

	data = node->GetData();
	pHead = node->GetNode();

	delete(node);
}

template <typename T>
void StackPtr<T>::Peek(T& data)
{
	if (pHead == nullptr)
		return;

	auto node = pHead;
	data = node->GetData();
}



template <typename T>
void StackPtr<T>::PrintAll()
{
	auto pNode = pHead;

	while (pNode != nullptr)
	{
		if (print != nullptr)
		{
			print(pNode->GetData());
			if (pNode->GetNode() != nullptr)
				printf(" -> ");
		}
		
		pNode = pNode->GetNode();
	}
	printf("\n");
}
