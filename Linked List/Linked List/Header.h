#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

///  
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
	/// 
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
	
	///
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

	///
	void Delete(T data) {
		Node<T>* FoundData = Find(data);
		if (FoundData != NULL) {
			Delete(FoundData);
		}
		else {
			cout << "That data is not in the List" << endl;
		}
	}

	///
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

	//
	void Display() {
		Node<T>* temp = Head;
		while (temp != NULL)
		{
			cout << temp ->Getdata() << " ";
			temp = temp->Next;
		}
		cout << endl;
	}


	// a test to see if the functions work properly will return false if it failed
	bool Diagnostics() {
		List<int> testList;

		/// checking the inset function 

		//check and see if the head and tail are set correctly on the first item
		testList.Insert(1);
		if ((testList.Head == NULL) || (testList.Tail == NULL)) {
			cout << "Error in adding first data" << endl;
			return false;
		}

		// check and see it=f the tail is moved properly on the second item
		testList.Insert(2);
		if (testList.Head == testList.Tail) {
			cout << "Error in adding data" << endl;
			return false;
		}


		/// checking the Delete function

		// check to see if the tail is moved correctly to one node
		testList.Delete(1);
		if (testList.Head != testList.Tail) {
			cout << "Error in deleting data down to one node" << endl;
			return false;
		}
		try {
			cout << "Testing Delete on Empty" << endl;
			//testing to see if it produces an error if it deletes somthing that isnt in the list
			testList.Delete(1);

			//testing to see if it produces an error if it deletes on a empty list
			testList.Delete(2);
			testList.Delete(1);
		}
		catch (...) {
			cout << "error with deleting" << endl;
			return false;
		}

		// testing to see if the head and tail are set correctly to null when the last node is deleted so the insert can set them again
		testList.Insert(1);
		if ((testList.Head == NULL) || (testList.Tail == NULL)) {
			cout << "Error in adding data after the list is cleared" << endl;
				return false;
		}

		/// checking the Find function

		// test to see if the find produces an error on somthing that isnt in the list
		if (testList.Find(3) != NULL) {
			cout << "Error in finding data not on the list" << endl;
			return false;
		}

		/// checking the Display function

		// test to see if it works
		cout << "Testing Display" << endl;
		testList.Display();

		// test to see if it works on an empty list
		testList.Delete(1);
		testList.Display();
		
		cout << "Completed Tests" << endl;
		return true;
	}
};