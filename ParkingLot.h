/*
* U2410043: Parking Lot - Array of lanes
* Implement multilanes. Each lane is Stack(LIFO) implement code of other member. 
* Implement extra feature with priority lane(for emergency, disables)
* will use temp queue for saving cars info
* Core functions: parkCar, removeCar, calculateCost, showAllLanes
*/


#pragma once
#include <iostream>
//for dynemic saving avaiable place in lanes
#include <vector>

//import member's code
#include "SingleParkingLane(Stack).h"  
#include"TempHoldLane(Queue).h"     

using namespace std;

// one parking lane
class LaneInfo {
public:
    //stack where car will placed
    Stack lane;
    //check is lane for prioriry car or for normal
    bool isPriorityLane;
};

//
class ParkingLot {
private:
    //array of lanes
    vector<LaneInfo> lanes;        
    //price for parking
    double ratePerHour;       
    //temp Queue
    ParkingQueue tempQueue;      

    //free place in normal lane
    vector<int> availableNormal;
    //free place in priority lane
    vector<int> availablePriority;

public:
    // Initialization, array of capictors for each lane, array is lanpriority for each, default price
    ParkingLot(vector<int> capacities, vector<bool> priorityFlags, double rate = 20.0) {
        ratePerHour = rate;

        for (int i = 0; i < capacities.size(); i++) {
            LaneInfo info;
            //set user capacity for lane
            info.lane.init(capacities[i]);
            //set is lane priorirty
            info.isPriorityLane = priorityFlags[i];
            //save lane in array
            lanes.push_back(info);

            //add indexes to array
            if (info.isPriorityLane) availablePriority.push_back(i);
            else availableNormal.push_back(i);
        }
    }

    //enter car
    //O(1) due using array of free places
    bool parkCar(int carID, double entryTime, bool isPriority) {
        //if car is priority
        if (isPriority) {
            //check is priority lanes have place
            if (!availablePriority.empty()) {
                int idx = availablePriority.back();
                //park car in priority car
                lanes[idx].lane.push(carID, entryTime);
                //output that car was parked in which lane
                cout << "Priority car " << carID << " parked in PRIORITY lane " << idx+1<< endl;
                //if lane become full, delete it from array of free places
                if (lanes[idx].lane.isFull()) availablePriority.pop_back();
                return true;
            }
            //if all priority lanes are full, try park in normal lane
            
            else if (!availableNormal.empty()) {
                //search is lane free
                int idx = availableNormal.back();
                //park car in lane
                lanes[idx].lane.push(carID, entryTime);
                //output, that priority car was parked in normal lane
                cout << "Priority car " << carID << " parked in NORMAL lane " << idx+1<< endl;
                //if lane becomes full, delete from array
                if (lanes[idx].lane.isFull()) availableNormal.pop_back();
                return true;
            }
        }
        //for normal cars
        //normal cars can park only in normal lane
        else {
            //check is lane have free place
            if (!availableNormal.empty()) {
                int idx = availableNormal.back();
                //park car
                lanes[idx].lane.push(carID, entryTime);
                //output, that car was parked in lane
                cout << "Normal car " << carID << " parked in lane " << idx+1 << endl;
                //if lane becomes full, delete from array
                if (lanes[idx].lane.isFull()) availableNormal.pop_back();
                return true;
            }
        }
        //else, parking is full, we can not park car
        cout << "Parking full for car " << carID << endl;
        return false;
    }

    //removeCar O(m) - wrost case
    void removeCar(int carID, double exitTime) {
        //search car in each lane
        for (int i = 0; i < lanes.size(); ++i) {
            //cost for parking
            double cost = 0;
            //how many moves where made
            int moves = 0;

            bool found = false;
            
            //while lane i is not empty
            while (!lanes[i].lane.isEmpty()) {
                //peek its id
                int topId = lanes[i].lane.peekID();
                //peek its entry time
                double topEntery = lanes[i].lane.peekEntryTime();

                //if peekde id is searching one
                if (topId == carID) {
                    //pop it
                    lanes[i].lane.pop(exitTime);
                    moves++;
                    //show in which move we poped it
                    cout << "Move: " << moves << endl;
                    cout << "Remove car " << carID << endl;

                    //calculate its cost
                    cost = calculateCost(carID, exitTime, i);
                    //car was finded
                    found = true;
                    break;
                }

                //if searching car not at the top
                else {
                    //pop car
                    lanes[i].lane.pop(exitTime);
                    //save it temp queue
                    tempQueue.enqueue(topId, topEntery);
                    moves++;
                    //output, that in move i car i was removed to temp queue
                    cout << "Move: " << moves << endl;
                    cout << "Moved car " << topId << " to temp queue\n";
                    //show temp queue and all lanes
                    //be sure, that car poped and enqueue properly
                    tempQueue.showQueue();
                    showAllLanes();
                }
            }

            //reenter all cars from queue to lane
            int restoreID;
            double restoreEntry;
            //while queue not become empty
            while (!tempQueue.isEmpty()) {
                //dequeue from rear, to save order in lane
                if (tempQueue.popBack(restoreID, restoreEntry)) {
                    //push to lane
                    lanes[i].lane.push(restoreID, restoreEntry);
                    moves++;
                    //output, that in move i car i was restored in lane
                    cout << "Move: " << moves << endl;
                    cout << "Moved car " << restoreID << " back to lane\n";
                    //show temp queue and all lanes
                    //be sure, that car pushed and dequeue properly
                    tempQueue.showQueue();
                    showAllLanes();
                }
            }

            //if we find car
            if (found) {
                //display that car was removed from lane i, cost for parking is, and how many moves we did to remove it
                cout << "Car " << carID << " removed from lane " << (i + 1) << ". Cost: " << cost << "$. Total moves: " << moves << endl;

                //ckeck if lane is free
                if (!lanes[i].lane.isFull()) {
                    //is lane priority
                    if (lanes[i].isPriorityLane) {
                        // ckeck index in  availablePriority
                        if (find(availablePriority.begin(), availablePriority.end(), i) == availablePriority.end()) {
                            availablePriority.push_back(i);
                        }
                    }
                    else {
                        //check index in availableNormal
                        if (find(availableNormal.begin(), availableNormal.end(), i) == availableNormal.end()) {
                            availableNormal.push_back(i);
                        }
                    }
                }

                return;
            }
        }
        //else car was not found
        cout << "Car " << carID << " not founded!\n";
    }

    //calculate cost in remove car
    //O(m)
    double calculateCost(int id, double exitTime, int i) {
        double entryTime = lanes[i].lane.findEntryTime(id);
        return (exitTime - entryTime) * ratePerHour;
    }

    //showAllLanes O(n*m)
    void showAllLanes() {
        for (int i = 0; i < lanes.size(); ++i) {
            cout << "Lane" << i + 1 << endl;
            lanes[i].lane.peek(); 
            cout << " \n";
        }
    }

    ~ParkingLot(){

        for (int i= 0; i < lanes.size(); i++) {
            lanes[i].lane.~Stack();
        }


         availableNormal.clear();
        availablePriority.clear();

        lanes.clear();

        cout << "ParkingLot destroyed and memory freed.\n";
    };
};
