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
	// 그러니까 0 부터 하면 2n 부터는.. 안되요..
	int idx = length + 1;
	
	/// <summary>
	// root (1) 가 아니라면
	/// </summary>
	while (idx != 1)
	{
		int parentIdx = GetParentIndex(idx);
		auto parentNode = heapArr[parentIdx];

		// 새로운 노드의 우선순위가 높을 경우
		// 계속 부모를 바꿔치기를 하는거..지..
		if (priority < parentNode->GetPriority())
		{
			// 부모보다 우선순위가 높다면 부모의 노드를 현재 노드에 넣고
			// 부모의 노드 인덱스를 저장해 준다.
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

	int parentIndex = 1; // 마지막 노드가 위치해야 할 인덱스
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
	// 크기보다 크다면 자식 노드가 없다는것
	if (GetLChildIndex(idx) > length)
	{
		return 0;
	}

	// 좌측 자식 노드막 있다는 것
	else if (GetLChildIndex(idx) == length)
	{
		return GetLChildIndex(idx);
	}
	else
	{
		int l = heapArr[GetLChildIndex(idx)]->GetPriority();
		int r = heapArr[GetRChildIndex(idx)]->GetPriority();

		// 우선 순위 가 높은 것에 따라
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


