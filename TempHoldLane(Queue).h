#pragma once
/*
* U2410032: Temperary Queue
* Create double ended queue with linked list implemintation
* while save cars information, when it will poped from stack
* Core functions: enqueue, dequeue, isEmpty, popBack, showQueue
*/

#include <iostream>
using namespace std;

//create node for linked list
class QueueNode {
public:
    int carID;
    double enteryTime;
    QueueNode* next;
};


// Class for temporary storage of cars when unblocking a blocked car
class ParkingQueue {
private:
    QueueNode* front;  // Pointer to the front of the queue
    QueueNode* rear;   // Pointer to the rear of the queue

public:
    //Create empty queue
    ParkingQueue() {
        front = NULL;
        rear = NULL;
    }

    // Add car to the end of the queue
    //O(1)
    void enqueue(int carID, double enteryTime) {
        //create new node
        QueueNode* newNode = new QueueNode;
        //set its info
        newNode->carID = carID;
        newNode->enteryTime = enteryTime;
        newNode->next = NULL;

        //if queue is empty
        if (isEmpty()) {
            front = rear = newNode;
        }
        //add new node after rear
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove a car from the front of the queue
    //O(1)
    bool dequeue() {
        if (isEmpty()) {
            return false;  // Queue is empty
        }

        //create pointer
        QueueNode* temp = front;
        //int carID = temp->carID;
        //double enteryTime = temp->enteryTime;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return true;
    }

    // 4. isEmpty() - Check if the queue is empty
    bool isEmpty() const {
        return front == NULL;
    }

    //delete el from rear
    //O(m)
    bool popBack(int& carId, double& enteryTime) {
        if (isEmpty()) {
            return false;
        }

        //if queue have only one element
        if (front == rear) {
            carId = front->carID;
            enteryTime = front->enteryTime;
            delete front;
            front = rear = NULL;
            return true;
        }

        //search till pre-last node
        QueueNode* cur = front;
        while (cur->next != rear) {
            cur = cur->next;
        }

        QueueNode* temp = rear;
        carId = temp->carID;
        enteryTime = temp->enteryTime;

        cur->next = NULL;
        rear = cur;
        delete temp;

        return true;

        
    }

    // 5. showQueue() - Print all cars in the queue
    //O(m)
    void showQueue() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Temp Queue (First->Last): ";
        QueueNode* current = front;
        while (current != NULL) {
            cout<<"[ Car Id: " << current->carID << ", Entery Time: "<< current->enteryTime<<" ], ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~ParkingQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};


