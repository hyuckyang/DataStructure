#include "LinkedList.h"
#include <stdio.h>

template <typename T>
LinkedNode<T>::LinkedNode()
{
	pLink = nullptr;
}

template <typename T>
LinkedNode<T>::LinkedNode(T data)
{
	this->data = data;
	pLink = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList()
{
	length = 0;
	pHead = nullptr;
	print = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(void (* print)(LinkedNode<T>* head))
{
	length = 0;
	pHead = nullptr;
	this->print = print;
}


template <typename T>
void LinkedList<T>::Insert(T data)
{
	LinkedNode<T>* node = new LinkedNode<T>(data);
	if (pHead == nullptr)
	{
		pHead = node;
	}
	else
	{
		node->SetLink(pHead);
		pHead = node;
	}

	length++;
}


template <typename T>
void LinkedList<T>::Add(T data)
{
	LinkedNode<T>* node = new LinkedNode<T>(data);
	if (pHead == nullptr)
	{
		pHead = node;
	}
	else
	{
		LinkedNode<T>* iter = pHead;
		while (iter->GetLink() != nullptr)
		{
			iter = iter->GetLink();
		}

		iter->SetLink(node);
	}

	length++;
}

template <typename T>
void LinkedList<T>::Remove()
{
	int index = length - 1;
	if (index < 0)
		return;

	RemoveAt(index);
}


template <typename T>
void LinkedList<T>::RemoveAt(int index)
{
	// 범위 이상 인덱스 면 삭제를 할수 없어요.
	if(index >= length)
		return;

	LinkedNode<T> *node = pHead;
	LinkedNode<T>* prev = nullptr;
	int current = 0;
	while (node -> GetLink() != nullptr)
	{
		if (index == current)
			break;

		prev = node;
		node = node->GetLink();
		current++;
	}

	if(node == nullptr)
		return;

	if(node == pHead)
	{
		pHead = nullptr;
	}
	else
	{
		prev->SetLink(node->GetLink());
	}

	delete(node);
	length--;
}

template <typename T>
void LinkedList<T>::Reverse()
{
	LinkedNode<T> *p, *q, *r;
	p = pHead;
	q = nullptr;
	r = nullptr;

	while (p != nullptr)
	{
		r = q;
		q = p;
		p = p->GetLink();
		q->SetLink(r);
	}

	// 시작점 변경
	pHead = q;
}


template <typename T>
void LinkedList<T>::Print()
{
	if (print != nullptr)
		print(pHead);
}