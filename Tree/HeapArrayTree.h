#pragma once
#define ARRAY_LEN 100

/**
 * 
 */
template <typename T>
class HATreeNode
{
	int priority; // ���� �������� ���� �켱����, ��Ģ
	T data;

public:
	HATreeNode(T data, int priority);

	int GetPriority() { return priority; }
	T GetData() { return data; }
};

template <typename T>
class HeapArrayTree
{
	int length;
	HATreeNode<T>* heapArr[ARRAY_LEN] = { nullptr, };
	void (*print)(T data);

	// ��� �˻�, �ڽ� or �θ� ��� �ε��� ( �迭 �ε��� ã�� )
	int GetParentIndex(int idx) { return idx / 2; }
	int GetLChildIndex(int idx) { return idx * 2; }
	int GetRChildIndex(int idx) { return GetLChildIndex(idx) + 1; }

	int GetHiPriChildIdx(int idx);
	
public:
	HeapArrayTree(void (*print)(T data))
	{
		this->print = print;
		length = 0;
	}

	void Insert(T data, int priority);
	void Delete();

	void Print();
	bool HIsEmpty() { return length <= 0; }


};


