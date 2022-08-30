#include "ArrayList.h"
#include <stdio.h>

template <typename T>
ArrayList<T>::ArrayList()
{
	length = 0;
	cursur = 0;
}

template <typename T>
void ArrayList<T>::Insert(T data)
{
	if(length >= LIST_LEN)
	{
		printf("Error. Full Length");
		return;
	}

	ArrayNode<T>* node = new ArrayNode<T>(data);
	arr[cursur] = node;

	cursur++;
	length++;
}

template <typename T>
bool ArrayList<T>::First(T &data)
{
	if(length == 0)
	{
		return false;
	}

	cursur = 0;
	data = arr[cursur];
	return true;
}

template <typename T>
bool ArrayList<T>::Next(T& data)
{
	if(cursur >= length -1)
	{
		// Cursur 가 현재 저장된 객체 끝까지 같다면
		return false;
	}

	cursur++;
	data = arr[cursur];

	return true;
}

template <typename T>
T ArrayList<T>::Remove()
{
	return RemoveAt(cursur);
}


template <typename T>
T ArrayList<T>::RemoveAt(int index)
{
	if (index >= length)
	{
		// 인덱스가 저장 범위를 초과하면 데이터가 없음으로 넘어감
		return false;
	}

	cursur = index;
	ArrayNode<T>* node = arr[index];
	T data = node->Get();

	for (int i = cursur; i < length; i++)
	{
		arr[i] = arr[i + 1];
	}

	delete(node);
	length--;
	cursur--;
	return data;
}

template <typename T>
void ArrayList<T>::print()
{
	// 작성 중
}






