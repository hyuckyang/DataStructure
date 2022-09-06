#include "HeapArrayTree.h"
#include <stdio.h>

template <typename T>
HATreeNode<T>::HATreeNode(T data, int priority)
{
	this->data = data;
	this->priority = priority;
}

template <typename T>
void HeapArrayTree<T>::Insert(T data, int priority)
{
	auto node = new HATreeNode<T>(data, priority);

	// parent = n
	// lChild = 2n
	// rChild = 2n +1
	// �׷��ϱ� 0 ���� �ϸ� 2n ���ʹ�.. �ȵǿ�..
	int idx = length + 1;
	
	/// <summary>
	// root (1) �� �ƴ϶��
	/// </summary>
	while (idx != 1)
	{
		int parentIdx = GetParentIndex(idx);
		auto parentNode = heapArr[parentIdx];

		// ���ο� ����� �켱������ ���� ���
		// ��� �θ� �ٲ�ġ�⸦ �ϴ°�..��..
		if (priority < parentNode->GetPriority())
		{
			// �θ𺸴� �켱������ ���ٸ� �θ��� ��带 ���� ��忡 �ְ�
			// �θ��� ��� �ε����� ������ �ش�.
			heapArr[idx] = parentNode;
			idx = parentIdx;
		}
		else
		{
			break;
		}
	}

	heapArr[idx] = node;
	length += 1;
}

template <typename T>
void HeapArrayTree<T>::Delete()
{
	auto root = heapArr[1];
	auto last = heapArr[length];

	int parentIndex = 1; // ������ ��尡 ��ġ�ؾ� �� �ε���
	int childIndex = 0;

	while (childIndex == GetHiPriChildIdx(parentIndex))
	{
		if (last->GetPriority() <= heapArr[childIndex]->GetPriority())
			break;

		heapArr[parentIndex] = heapArr[childIndex];
		parentIndex = childIndex;
	}
	
	heapArr[parentIndex] = last;
	length -= 1;
}

template <typename T>
int HeapArrayTree<T>::GetHiPriChildIdx(int idx)
{
	// ũ�⺸�� ũ�ٸ� �ڽ� ��尡 ���ٴ°�
	if (GetLChildIndex(idx) > length)
	{
		return 0;
	}

	// ���� �ڽ� ��帷 �ִٴ� ��
	else if (GetLChildIndex(idx) == length)
	{
		return GetLChildIndex(idx);
	}
	else
	{
		int l = heapArr[GetLChildIndex(idx)]->GetPriority();
		int r = heapArr[GetRChildIndex(idx)]->GetPriority();

		// �켱 ���� �� ���� �Ϳ� ����
		if (l > r)
			return GetRChildIndex(idx);
		else
			return GetLChildIndex(idx);
	}
}



template <typename T>
void HeapArrayTree<T>::Print()
{
	for (int i = 1; i <= length; i++)
	{
		auto node = heapArr[i];
		if (node == nullptr)
			continue;

		printf("priority %d data == ", node->GetPriority());
		print(node->GetData());
		printf(" \n");
	}
}


