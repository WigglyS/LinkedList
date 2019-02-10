#pragma once
#include <string>
#include <iostream>
//this is for system("CLS");
#include <stdlib.h>

using namespace std;

///  The Node class is to store data of a generic type and acess to the next and previous in the list
template<typename T>
class Node
{
public:
	Node* GetPrevious() { return Previous; }
	void SetPrevious(Node* prev) { Previous  =  prev; }
	Node* GetNext() { return Next; }
	void SetNext(Node* next) { Next = next; }

	T Getdata() { return data; };
	void SetData(T d) { data = d; };
private:
	Node* Previous = nullptr;
	Node* Next = nullptr;
	T data;
};

//The list class is for holding acess to the head and tail as well as the funtions for adding deleting etc for the list
template<typename T>
class LinkedList
{
private:
	Node<T>* Head = nullptr;
	Node<T>* Tail = nullptr;
public:
	/// This function inserts the data you pass it to the end of the list
	void Insert(T data)
	{
		//this condition is for the first node created, the nodes pointers are set to null and the head and tail are set to it since its the only node
		if (Head == nullptr && Tail == nullptr)
		{
			Node<T>* newNode = new Node<T>;
			newNode->SetData(data);
			newNode->SetPrevious(NULL);
			newNode->SetNext(NULL);
			Head = newNode;
			Tail = newNode;

		//all the other nodes are handled by this one, adds a new node rearanges the pointers of the previous node and the new one and moves the tail to the new node
		}else
		{
			Node<T>* newNode = new Node<T>;
			newNode->SetData(data);
			newNode->SetPrevious(Tail);
			Tail->SetNext(newNode);
			newNode->SetNext(NULL);
			Tail = newNode;
		}

	}
	
	///Deletes the node of which you give the pointer to
	void Delete(Node<T>* N)
	{
		//this first one is the general case, moves the pointers on both sides of the node to be deleted
		if (Tail != N && Head != N) {
			N->GetPrevious()->SetNext(N->GetNext());
			N->GetNext()->SetPrevious(N->GetPrevious());
		}
		//these next 2 handle it if it  either the head or tail or both, it moves the head to the next/null if thereisnt one and sets the its previous to null then 
		// the same with the tail using previous instead of next
		if(Head == N)
		{
			Head = N->GetNext();
			if (N->GetNext() != NULL) {
				N->GetNext()->SetPrevious(NULL);
			}
		}
		if(Tail == N)
		{
			Tail= N->GetPrevious();
			if (N->GetPrevious() != NULL) {
				N->GetPrevious()->SetNext(NULL);
			}
			
		}
		//in any case we made the node to be deleted pointers = to null then finaly delete it
			N->SetNext(NULL);
			N->SetPrevious(NULL);
			delete N;
	}

	///this delete funcion takes data instead of a pointer,  still  deletes the node which contains the data
	void Delete(T data) {
		// uses the find function below to get a pointer then just uses the destroy function above
		Node<T>* FoundData = Find(data);
		if (FoundData != NULL) {
			Delete(FoundData);
		}
		else {
			cout << "That data is not in the List" << endl;
		}
	}

	///loops through all the nodes and if it finds a  match to the data then it returns a pointer to it, if it doesnt find it it returns null
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
				temp = temp->GetNext();
			}
		}
		return NULL;
	}

	//loops through all the nodes and displays their data
	void Display() {
		Node<T>* temp = Head;
		//if the whole list is emply dont print anyhting otherwise  print the list and an endl;
		if (temp != NULL) {
			cout << "The list contains: " << endl;
			while (temp != NULL)
			{
				cout << temp->Getdata() << " ";
				temp = temp->GetNext();
			}
			cout << endl;
		}
	}


	// a test to see if the functions work properly will return false if it failed
	bool Diagnostics() {
		LinkedList<int> testList;


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