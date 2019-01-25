#pragma once
#include <string>

using namespace std;

template<typename T>

class Node
{
	T data;

	Node* Previous = nullptr;
	Node* Next = nullptr;
};

template<typename T>
class List
{
	Node<T>* Head = nullptr;
	Node<T>* Tail = nullptr;

	void Add(T data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Node<T> newNode = new Node<T>;
			newNode.data = data;
			newNode.Previous = NULL;
			newNode.Next = NULL;
			Head = &newNode;
			Tail = &newNode;
		}else
		{
			Node<T> newNode = new Node<T>;
			newNode.data = data;
			newNode.Next = NULL;
			//newNode.Previous =
			Tail = &newNode;
		}

	}
	void Remove()
	{
		Node<T>* newEnd = Tail->Previous;
		Destroy(*Tail);
		Tail = newEnd;
	}
	void Insert(T data, int position)
	{
		
	}
	void RemoveFrom(int position)
	{
		
	}

};