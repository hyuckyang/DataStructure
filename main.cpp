#include <cmath>
#include <stdio.h>
#include "List/ArrayList.h"
#include "List/ArrayList.cpp"
#include "List/LinkedList.h"
#include "List/LinkedList.cpp"
#include "List/DoubleLinkedList.h"
#include "List/DoubleLinkedList.cpp"
#include "Tree/HeapArrayTree.h"
#include "Tree/HeapArrayTree.cpp"

#pragma region 팩토리얼 (Factorial) 함수 (재귀함수)

int Factorial(int n)
{
	if (n == 0)
		return 1;

	return n * Factorial(n - 1);
}

void FactorialPrint()
{
	printf("--- Factorial ---\n");
	printf("Factorial 1! = %d \n", Factorial(1));
	printf("------------------\n");
}

#pragma endregion 

#pragma region 피보나치 수열 (Fibonacci Sequence) 함수

/**
 * 0 + 1
 * 1 + 1 ... ...
 */
int Fibonacci(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;

	//printf("Fibonacci(%d - 1) = %d + Fibonacci(%d - 2) = %d\n", n, Fibonacci(n - 1), n, Fibonacci(n - 2));
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void FibonacciPrint()
{
	printf("--- Fibonacci ---\n");
	printf("Fibonacci 5 = %d \n", Fibonacci(5));
	printf("------------------\n");
}

#pragma endregion 

#pragma region 이진탐색 (Binary Search)

int BinarySearch(int arr[], int length, int target)
{
	int firstIndex = 0; // 첫번째 인덱스
	int lastIndex = length - 1; // 마지막 인덱스
	int middleIndex = 0; // 현재의 인덱싱

	while (firstIndex <= lastIndex)
	{
		middleIndex = (firstIndex + lastIndex) / 2; // 중앙을 찾아요.

		if (target == arr[middleIndex])
		{
			return middleIndex;
		}
		else
		{
			if (target < arr[middleIndex])
			{
				lastIndex = middleIndex - 1;
			}
			else
			{
				firstIndex = middleIndex + 1;
			}
		}
	}
	return 0;
}

/**
 * 재귀함수 활용
 */
int BinarySearchRecur(int arr[], int first, int last, int target)
{
	if (first > last)
		return -1; // 계속 탐색을 하여 퍼스트 인덱스 역순이 되면 탐색 실패

	int midIndex = (first + last) / 2;
	int midValue = arr[midIndex];

	if (target == midValue)
	{
		return midIndex;
	}
	else
	{
		if (target < midValue)
		{
			return BinarySearchRecur(arr, first, midIndex - 1, target);
		}
		else
		{
			return BinarySearchRecur(arr, midIndex + 1, last, target);;
		}
	}
}

void BinarySearchPrint()
{
	printf("--- BinarySearch ---\n");
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("BSearch Target = 4 index %d \n", BinarySearch(arr, 5, 5));
	printf("BSearch Recur Target = 4 index %d \n", BinarySearchRecur(arr, 0, 4, 5));
}

#pragma endregion

#pragma region List

/**
 * 작성중
 */
void ArrayListPrint()
{
	ArrayList<int>* arr = new ArrayList<int>();
	arr->Insert(11);
	arr->Insert(11);
	arr->Insert(22);
	arr->Insert(22);
	arr->Insert(33);
	arr->Remove();
	arr->RemoveAt(1);
	arr->Print();
}

void LinkedListPrintEvent(LinkedNode<int>* head)
{
	LinkedNode<int>* node = head;
	while (node != nullptr)
	{
		printf("%d ", node->GetData());
		if (node->GetLink() != nullptr)
			printf("-> ");
		else
			printf("\n");

		node = node->GetLink();
	}
}

void LinkedListPrint()
{
	LinkedList<int>* list = new LinkedList<int>(LinkedListPrintEvent);
	list->Add(1);
	list->Add(2);
	list->Add(3);
	list->Add(4);
	list->Print();
	list->Reverse();
	list->Print();

}

void DoubleLinkedListPrintEvent(DoubleLinkedNode<int>* head, bool reverse)
{
	DoubleLinkedNode<int>* pNode = head;
	if (pNode == nullptr)
		return;

	if (reverse)
	{
		while (pNode->GetTail() != nullptr)
			   pNode = pNode->GetTail();
	}

	while (pNode != nullptr)
	{
		printf("%d ", pNode->GetData());
		
		DoubleLinkedNode<int>* pNext = pNode->GetTail();
		if (reverse)
			pNext = pNode->GetHead();
		
		if (pNext != nullptr)
			printf("-> ");
		else
			printf("\n");
		
		pNode = pNext;
	}
}

void DoubleLinkedListPrint()
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>(DoubleLinkedListPrintEvent);
	list->Add(3);
	list->Add(4);
	list->Insert(2);
	list->Insert(1);
	list->Print(false);
	list->Remove();
	list->Print(false);

	list->RemoveAt(1);
	list->Print(false);

	list->RemoveAt(1);
	list->Print(false);

	list->RemoveAt(0);
	list->Print(false);

}

#pragma endregion 

#pragma region Tree

void HeapArrayTreeDataPrintFunc(char data)
{
	printf("%c", data);
}

void HeapArrayTreePrint()
{
	auto heapArr = new HeapArrayTree<char>(HeapArrayTreeDataPrintFunc);
	heapArr->Insert('A', 1);
	heapArr->Insert('B', 2);
	heapArr->Insert('C', 3);
	heapArr->Insert('D', 4);
	heapArr->Insert('E', 5);
	heapArr->Insert('F', 6);
	//heapArr->Insert(7, 7);
	heapArr->Delete();

	heapArr->Print();
}


#pragma endregion 

int main()
{
	/*FactorialPrint();
	FibonacciPrint();
	BinarySearchPrint();
	ArrayListPrint();
	LinkedListPrint();
	DoubleLinkedListPrint();*/

	HeapArrayTreePrint();
}