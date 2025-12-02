#pragma once
/*
* U2410010: Priority Waiting Zone
* Create priority and normal queue with linked list implementation
* Using Queue properties FCFS to simulate real-life queue
* limit number of cars in waiting zone
* Core functions: enqueue, dequeue, isEmpty, peek, show
*/

#include <iostream>
using namespace std;

// create node class
//for linked list implemintation
class PriorityNode {
public:
    int carId;
    PriorityNode* next;
};

// create queue with linked list
//implements FIFO
class Queue {
private:
    //pointer to the first node
    //for dequeue
    PriorityNode* front;

    //pointer to the last node
    //for enqueue
    PriorityNode* rear;
public:
    //create empty queue
    Queue() {
        front = rear = NULL;
    }

    //check if queue empty
    bool isEmpty() {
        return front == NULL;
    }

    //enter new car
    //O(1)
    void enqueue(int id) {
        //create new node
        PriorityNode* temp = new PriorityNode;

        //set data for new node
        temp->carId = id;
        temp->next = NULL;

        //if queue is empty
        if (front == NULL && rear == NULL) {
            //new node is first and last one
            front = rear = temp;
        }
        else {
            //enter after last node
            rear->next = temp;
            rear = temp;
        }
    }

    //delete first node
    //O(1)
    int dequeue() {
        //if empty
        if (isEmpty()) return -1;

        else {
            //save pointer to current front
            PriorityNode* temp = front;
            //save its value
            int id = temp->carId;
            //update front
            front = front->next;
            //if front becomes null -> queue is empty node
            if (front == NULL) rear = NULL;
            //delete node
            delete temp;
            //return ids value
            return id;
        }

    }

    //see front element
    int peek() {
        if (isEmpty()) return -1;
        return front->carId;
    }

    //display all elemts
    //O(n)
    void show() {
        PriorityNode* ptr = front;
        while (ptr) {
            cout << "Car Id: " << ptr->carId << endl;
            ptr = ptr->next;
        }
    }

    //destructor
    ~Queue() {
        while (front != NULL) {
            PriorityNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
    }
};

class PriorityQueue {
private:
    //with 2 queues
    Queue highQueue;   // for priority
    Queue normalQueue; // for normal

    //max capacity for queue
    static const int MAX_HIGH = 3;
    static const int MAX_NORMAL = 2;

    //how many cars in queue
    int highCount = 0, normalCount = 0;

    //arrays for saving time
    double highEntryTime[MAX_HIGH];
    double normalEntryTime[MAX_NORMAL];

public:
    //enter car
    //O(1)
    void enqueue(int carId, bool isPriority, double entryTime) {
        //if car priority, but # current cars is equal to max capacity 
        if (isPriority && highCount >= MAX_HIGH) {
            //queue is full
            cout << "High Priority queue is Full!\n";
            return;
        }

        //if car is not priority, but # current cars is equal to max capacity 
        if (!isPriority && normalCount >= MAX_NORMAL) {
            //queue is full
            cout << "Noramal Priority queue is Full!\n";
            return;
        }

        //if car priority
        if (isPriority) {
            //add to priority queue
            highQueue.enqueue(carId);
            //save entry Time
            highEntryTime[highCount] = entryTime;

            //update # current cars
            highCount++;
        }
        else {
            //add to normal queue
            normalQueue.enqueue(carId);
            //save entry Time
            normalEntryTime[normalCount] = entryTime;

            //update # current cars
            normalCount++;
        }
    }

    //delete cars
    //O(1)
    int dequeue(double& entryTime, bool& isPriority) {
        //if priority queue nit empty
        if (!highQueue.isEmpty()) {
            isPriority = true;

            //remove it
            int id = highQueue.dequeue();

            entryTime = highEntryTime[0];

            for (int i = 1; i < highCount; i++)
                highEntryTime[i - 1] = highEntryTime[i];

            //update # current cars
            highCount--;
            //return its id
            return id;
        }
        else if (!normalQueue.isEmpty()) {
            isPriority = false;

            //remove from normal queue
            int id = normalQueue.dequeue();

            entryTime = normalEntryTime[0];

            for (int i = 1; i < normalCount; i++)
                highEntryTime[i - 1] = normalEntryTime[i];

            //update # current cars
            normalCount--;
            //return its id
            return id;
        }

        else {
            
            cout << "Waiting zone is empty!\n";
            entryTime = -1;
            isPriority = false;
            return -1;
        }
    }

    //check is queues are empty
    //O(1)
    bool isEmpty() {
        return highQueue.isEmpty() && normalQueue.isEmpty();
    }

    //display both queues
    //O(n)
    void show() {

        if (isEmpty()) {
            cout << "Waiting zone is Empty\n";
            return;
        }

        else {

            cout << "\nHigh Priority Queue: \n";
            highQueue.show();
            cout << "Entry Time: ";
            for (int i = 0; i < highCount; i++) {
                cout << highEntryTime[i] << " \n";
            }
            cout << "\n";

            cout << "\nNormal Queue: \n";
            normalQueue.show();
            cout << "Entry Time: ";
            for (int i = 0; i < normalCount; i++) {
                cout << normalEntryTime[i] << " \n";
            }
            cout << "\n";
        }


    }

    //destruct both queues
    ~PriorityQueue() {
        while (!highQueue.isEmpty()) {
            highQueue.dequeue();
        }
        highCount = 0;

        while (!normalQueue.isEmpty()) {
            normalQueue.dequeue();
        }
        normalCount = 0;

        for (int i = 0; i < MAX_HIGH; i++)
            highEntryTime[i] = 0.0;

        for (int i = 0; i < MAX_NORMAL; i++)
            normalEntryTime[i] = 0.0;
    }
};
