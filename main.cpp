#include <cmath>
#include <stdio.h>

#pragma region ���丮�� (Factorial) �Լ� (����Լ�)

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

#pragma region �Ǻ���ġ ���� (Fibonacci Sequence) �Լ�

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

#pragma region ����Ž�� (Binary Search)

int BinarySearch(int arr[], int length, int target)
{
	int firstIndex = 0; // ù��° �ε���
	int lastIndex = length - 1; // ������ �ε���
	int middleIndex = 0; // ������ �ε���

	while (firstIndex <= lastIndex)
	{
		middleIndex = (firstIndex + lastIndex) / 2; // �߾��� ã�ƿ�.

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
 * ����Լ� Ȱ��
 */
int BinarySearchRecur(int arr[], int first, int last, int target)
{
	if (first > last)
		return -1; // ��� Ž���� �Ͽ� �۽�Ʈ �ε��� ������ �Ǹ� Ž�� ����

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