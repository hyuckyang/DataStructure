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

	void (*print)(LinkedNode<T>* head); // print ����


public:
	LinkedList();
	LinkedList(void (*print)(LinkedNode<T>* head));
	~LinkedList() { }

	void Insert(T data); // �տ��� 
	void Add(T data); // �ڿ���

	void Remove();
	void RemoveAt(int index);

	void Reverse(); // ����Ʈ�� �������� ������

	void Print();
};