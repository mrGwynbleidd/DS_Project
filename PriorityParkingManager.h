#pragma once
/*
* U2410043: Manager
* manager create object of waiting zone and parking lot
* car enter to the waiting zone and try to park in lot
* if parking is full it is stay in waiting zone
*/

#include<iostream>
//import member's code
#include"ParkingLot.h"
#include"WaitingZone(PriprityQueue).h"

using namespace std;

//car park manager class
class PrioprityManager {
private:
	//create object of waiting zone and park lot
	PriorityQueue waitingZone;
	ParkingLot& lot;

public:
	//initilaize park lot
	PrioprityManager(ParkingLot& p) : lot(p){}

	//park car
	//O(k)
	void addCar(int carId, bool isPriority, double enteryTime) {
		//firstly car enter to waiting zone
		//O(1)
		waitingZone.enqueue(carId, isPriority, enteryTime);
		cout << "Car: " << carId << " is entered to waiting zone!\n";

		//try to park car in parking lane
		//O(k)
		tryFillFromWaiting();
	}

	//will park cars in lot till paking will not become fill
	//O(1), O(W)
	void tryFillFromWaiting() {
		//till waiting zone has cars
		while (!waitingZone.isEmpty()) {
			double entryTime = 0.0;
			bool isPriority = false;

			int carId = waitingZone.dequeue(entryTime, isPriority);
			if (carId == -1) {
			//	// queue is empty
				return;
			}

			bool parked = lot.parkCar(carId, entryTime, isPriority);
			if (!parked) {
			//	// parking os full - return car to queue
			//	// end cycle
				waitingZone.enqueue(carId, isPriority, entryTime);
				cout << "No free space for car " << carId
					<< ". Returned back to waiting zone.\n";
				return;
			}
			
			else {
				cout << "Car " << carId
					<< " left waiting zone and was parked successfully.\n";
			}
		}
	}

	//show waiting zone
	//O(n)
	void showWaitingZone() {
		waitingZone.show();
	}

	~PrioprityManager() {
		double time;
		bool isPr;

		while (!waitingZone.isEmpty()) {
			waitingZone.dequeue(time, isPr);
		}

		cout << "PriorityManager destroyed. Waiting zone cleared.\n";
	}
};
