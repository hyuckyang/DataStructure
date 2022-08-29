#include <cmath>
#include <stdio.h>

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

int main()
{
	FactorialPrint();
	FibonacciPrint();
	BinarySearchPrint();
}