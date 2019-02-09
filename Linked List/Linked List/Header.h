#pragma once
#include <string>
#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
	Node* Previous = nullptr;
	Node* Next = nullptr;

	T Getdata() { return data; };
	void SetData(T d) { data = d; };
private:
	T data;
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
			Node<T>* newNode = new Node<T>;
			newNode->SetData(data);
			newNode->Previous = NULL;
			newNode->Next = NULL;
			Head = newNode;
			Tail = newNode;
		}else
		{
			Node<T>* newNode = new Node<T>;
			newNode->SetData(data);
			newNode->Previous = Tail;
			Tail->Next = newNode;
			newNode->Next = NULL;
			Tail = newNode;
		}

	}
	
	void Delete(Node<T>* N)
	{
		if (Tail != N && Head != N) {
			N->Previous->Next = N->Next;
			N->Next->Previous = N->Previous;
		}
		if(Head == N)
		{
			Head = N->Next;
			if (N->Next != NULL) {
				N->Next->Previous = NULL;
			}
		}
		if(Tail == N)
		{
			Tail= N->Previous;
			if (N->Previous != NULL) {
				N->Previous->Next = NULL;
			}
			
		}
			N->Next = NULL;
			N->Previous = NULL;
			delete N;
	}

	void Delete(T data) {
		Node<T>* FoundData = Find(data);
		if (FoundData != NULL) {
			Delete(FoundData);
		}
		else {
			cout << "That data is not in the List" << endl;
		}
	}

	Node<T>* Find(T data)
	{
		Node<T>* temp = Head;
		while(temp != NULL)
		{
			if(temp->Getdata() == data)
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

	void Display() {
		Node<T>* temp = Head;
		while (temp != NULL)
		{
			cout << temp ->Getdata() << " ";
			temp = temp->Next;
		}
		cout << endl;
	}

};