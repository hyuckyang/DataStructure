#pragma once

template <typename T>
class LinkedNode
{
	T data;
	LinkedNode* pLink;

public:
	LinkedNode();
	LinkedNode(T data);
	~LinkedNode(){}

	T GetData() { return data; }

	LinkedNode* GetLink() { return pLink; }
	void SetLink(LinkedNode<T>* node) { pLink = node; }
};

template <typename T>
class LinkedList
{
	int length;
	LinkedNode<T>* pHead;

	void (*print)(LinkedNode<T>* head); // print 정의


public:
	LinkedList();
	LinkedList(void (*print)(LinkedNode<T>* head));
	~LinkedList() { }

	void Insert(T data); // 앞에서 
	void Add(T data); // 뒤에서

	void Remove();
	void RemoveAt(int index);

	void Reverse(); // 리스트를 역순으로 변경함

	void Print();
};