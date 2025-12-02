#pragma once
/*
* U2410049: Single Parking lane implementation
* Create single parking lane using stack with linked list implementation
* Using stack properties LIFO to simullate real-life narrow parking lane
* Core functions: pushCar(), popCar(), peek(), isEmpty(), showLaneCars()
*/

#include <iostream>
using namespace std;

//create Node class
//for single linked list
class StackNode {
public:
	//save car id
	int info;
	//save entery time
	double enteryTime;
	//save exit time
	double exitTime;
	//link to next node
	StackNode* next;
};

//create Stack with linked list impelementation
class Stack {
	//prevent direct access from outside to info un top
private:
	StackNode* top;


public:
	int capacity;
	int size;
	int price;

	//constructor, create empty stack
	Stack() {
		top = NULL;
		//set default values
		capacity = 3; //max capcity in lane
		size = 0; //# cars in lane
		price = 20.0; //price for  parking

	}

	//save users capacity for lane
	void init(int cap) {
		capacity = cap;
	}

	//check if lane is full
	//O(1)
	bool isFull() {
		if (size == capacity) {
			return true;
		}
		else {
			return false;
		}
	}

	//add car id to top of lane
	//O(1)
	void push(int carID, double entryTime) {
		//if lane is full, car can not enter
		if (isFull()) {
			cout << "Lane is full, cannot add car " << carID << endl;
			return;
		}

		//create node
		StackNode* node = new StackNode;
		//enter cars value
		node->info = carID;
		node->enteryTime = entryTime;
		//set default exit time
		node->exitTime = 0.0;
		//set link to next node
		node->next = top;
		//update top node
		top = node;
		size++;   // increase size size
	}


	//delete car from lane
	//O(1)
	void pop(double exitTime) {
		//if lane is empty, we can not pop it
		if (isEmpty()) {
			cout << "Lane is Empty, Can not remove car!\n";
			return;
		}
		else {
			//set exit time
			top->exitTime = exitTime;
			//create poiter
			StackNode* temp = top;
			//update top node
			top = top->next;
			//delete node
			delete temp;
			//decrease size
			size--;
		}
	}

	//get car id from top el
	//O(1)
	int peekID() {
		if (isEmpty()) return -1;
		return top->info;
	}

	//get entry time from top el
	//O(1)
	double peekEntryTime() {
		if (isEmpty()) return -1;
		return top->enteryTime;
	}

	//find entry time by its car id
	//O(m)
	double findEntryTime(int carID) {
		//create poiter in top el
		StackNode* cur = top;
		//search till end of lane
		while (cur != NULL) {
			if (cur->info == carID) return cur->enteryTime;
			cur = cur->next;
		}
		return -1;
	}

	//display all el in lane
	//O(m)
	void peek() {
		//if lane is empty
		if (isEmpty()) {
			cout << "Lane is empty.\n";
			return;
		}

		//create pointer at top el
		StackNode* cur = top;
		cout << "Lane(Top->Button) : ";
		//display all el
		while (cur != NULL) {
			cout << "[" << cur->info << " at " << cur->enteryTime << "] ";
			cur = cur->next;
		}
		cout << endl;
	}

	//check is stack empty
	//O(1)
	bool isEmpty() {
		//if top = null, it means there is no data
		if (top == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	//delete all allocated memory
	~Stack() {
		while (!isEmpty()) {
			StackNode* temp = top;
			top = top->next;
			delete temp;
		}
	}


};