#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;

//nodes for storing doubly linked list
struct Node 
{
	int data; //data stored in the node
	Node* prev; //pointer to the previous node
	Node* next; //pointer to the next node

	Node (int value) : data(value), prev (nullptr){} //constructor to initialize the node
};

//stack class
class Stack 
{
	private:
		Node* top; //pointer to the most recent node (top) of the stack
public:
	Stack() : top(nullptr) {} //constructor to initialize an empty stack
	//Push function to add new node to the top of the stack
	void Insert(int value)
	{
		Node* newNode = new Node(value);
		if (top != nullptr)
		{
			newNode->prev = top; //link the new code to the current top
		}
		top = newNode; //update the top to point to the new node

	}

	//Pop (remove) function to delete the top node from the stack
	void Remove()
	{
		if (top == nullptr) //check to see if the stack is empty
		{
			cout << "Stack is empty" << endl;
			return;
		}
		Node* temp = top; //store the current top node temporarily
		top = top->prev; //move the top pointer to the previous node
		delete temp; //delete the removed node

	}

//Print function
void Print()
{
	Node* current = top; //set current node
	while (current != nullptr)
	{
		cout << current->data << " " << endl; //print current node
		current = current->prev; //move to the previous node
	}
}
};

//Queue class
class Queue
{
private:
	Node* first; //pointer to the first node in the queue
	Node* last; //pointer to the last node in the queue
public:
	//constructor for an empty queue
	Queue() : first(nullptr), last(nullptr) {}

	//Insert into queue
	void Insert(int value)
	{
		Node* newNode = new Node(value);
		if (last != nullptr)
		{
			last->next = newNode; //link the last element to the new node
			newNode->prev = last; //link the new node to the current end of the queue
		}
		last = newNode; //update the last element to point to the new node

		if (first == nullptr) //if the queue was empty, update the first as well
		{
			first = newNode;
		}
	}

	//remove (pop)
	void Remove()
	{
		if (first == nullptr) //check if the queue is empty
		{
			cout << "Queue is empty" << endl;
			return;
		}
		Node* temp = first; // store the current front node in a temp location
		first = first->next; // move the pointer to the next node
		if (first != nullptr)
		{
			first->prev = nullptr; //disconnect the removed node
		}
		else
		{
			last = nullptr; //if the queue is empty, update last
		}
		delete temp; //delete the removed node

	}

	//print function
	void Print()
	{
		Node* current = first; //set the current node
		while (current != nullptr) //while queue is not at the end
		{
			cout << current->data << " " << endl;
			current = current->next; //traverse through the queue
		}
		cout << endl;
	}

};

//Measuring the time to insert and remove elements within the stack and queue
void measureTime()
{
	Stack stack; //using the stack class to perform operations
	Queue queue;// using the queue class to perform operations

	const int sizes[] = { 100, 1000, 10000 }; //array of input sizes

	//loop through the sizes of the array
	for (int size : sizes)
	{
		//measure stack insert
		auto start = chrono::high_resolution_clock::now(); //start time
		for (int i = 0; i < size; i++)
		{
			stack.Insert(rand()); //insert random numbers into the stack
		}
		auto end = chrono::high_resolution_clock::now(); // End time
		cout << "Stack Insert " << size << ": " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds\n";

		//measure queue insert
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < size; i++)
		{
			queue.Insert(rand());
		}
		end = chrono::high_resolution_clock::now();
		cout << "Queue Insert " << size << ": " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds\n";
		
		//measure stack remove (pop)
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < size; i++)
		{
			stack.Remove(); //remove elements from the stack
		}
		end = chrono::high_resolution_clock::now();
		cout << "Stack Remove " << size << ": " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds\n";
		
		
		/*
		//measure queue remove (pop)
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < size; i++)
		{
			queue.Remove(); //remove elements from queue

		}
		end = chrono::high_resolution_clock::now();
		cout << "Queue Remove " << size << ": " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds\n";
		*/	
	}




} 

int main() {
	measureTime(); // Run the performance measurement tests
	return 0;
}