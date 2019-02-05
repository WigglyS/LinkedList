#pragma once
#include <string>
#include <iostream>

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
private:
	Node<T>* Head = nullptr;
	Node<T>* Tail = nullptr;
public:
	void Insert(T data)
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
			newNode.Previous = Tail;
			Tail->Next = newNode;
			newNode.Next = NULL;
			Tail = &newNode;
		}

	}
	void Remove()
	{
		Node<T>* newEnd = Tail->Previous;
		Destroy(*Tail);
		Tail = newEnd;
	}
	void Delete(Node* N)
	{
		if(Head == N)
		{
			Head = N->Next;
			N->Next->Previous = NULL;
			N->Next = NULL;
			delete N;
		}
		else if(Tail == N)
		{
			Tail= N->Previous;
			N->Previous->Next = NULL;
			N->Previous = NULL;
			delete N;
		}
		else
		{
			N->Previous->Next = N->Next;
			N->Next->Previous = N->Previous;
			N->Next = NULL;
			N->Previous = NULL;
			delete N;
		}
	}
	Node* Find(T data)
	{
		Node* temp = Head;
		while(temp != NULL)
		{
			if(temp->data == data)
			{
				return temp;
			}
			else
			{
				temp = temp->Next;
			}
		}
		return NULL;
	}

};