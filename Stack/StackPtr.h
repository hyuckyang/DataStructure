#pragma once

template <typename T>
class StackPtrNode
{
	T data;
	StackPtrNode<T>* node;

public:
	StackPtrNode(T data);

	T GetData() { return data; }

	void SetNode(StackPtrNode<T>* node) { this->node = node; }
	StackPtrNode<T>* GetNode() { return node; }
};

template <typename T>
class StackPtr
{
protected:
	StackPtrNode<T>* pHead;
	void (*print)(T data);
	
public:

	StackPtr(void (*print)(T data));

	void Push(T data);
	void Pop(T& data);
	void Peek(T& data);
	void PrintAll();

};