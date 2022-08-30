#pragma once
#define LIST_LEN 100

template<typename T>
class ArrayNode
{
	T data;
public:
	void Set(T data) { this->data = data; }

	T Get() { return data; }
};


/**
 * �迭 ��� ����Ʈ
 * ���� �ڷᱸ�� ���
 */
template<typename T>
class ArrayList
{
	ArrayNode<T>* arr[LIST_LEN];
	int length;
	int cursur;

public:
	ArrayList();
	~ArrayList(){}

	void Insert(T data);
	bool First(T& data);
	bool Next(T& data);
	T Remove ();
	T RemoveAt(int index);

	void print();

	int GetLength() { return length; }

};



