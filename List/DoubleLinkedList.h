#pragma once

template <typename T>
class DoubleLinkedNode
{
	T data;
	DoubleLinkedNode<T>* pHead;
	DoubleLinkedNode<T>* pTail;

public:

	DoubleLinkedNode();
	DoubleLinkedNode(T data);
	~DoubleLinkedNode() { }

	T GetData() { return data; }
	void SetData(T data) { this->data = data; }

	void SetHead(DoubleLinkedNode<T>* head) { pHead = head; }
	DoubleLinkedNode<T>* GetHead() { return pHead; }

	void SetTail(DoubleLinkedNode<T>* tail) { pTail = tail; }
	DoubleLinkedNode<T>* GetTail() { return pTail; }
};

template <typename T>
class DoubleLinkedList
{
	DoubleLinkedNode<T>* pHead;
	void (*print)(DoubleLinkedNode<T>* head, bool reverse);

public:
	DoubleLinkedList(void (*print)(DoubleLinkedNode<T>* head, bool));
	~DoubleLinkedList(){}

	void Insert(T data);
	void Add(T data);
	void Remove();
	void RemoveAt(int index);

	int GetLength();
	void Print(bool reverse);
	
};