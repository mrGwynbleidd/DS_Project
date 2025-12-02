//here i test methods of manager, parking lot
//and whole programm

#include <iostream>
#include"SingleParkingLane(Stack).h"
#include"TempHoldLane(Queue).h"
#include"ParkingLot.h"
#include"WaitingZone(PriprityQueue).h"
#include"PriorityParkingManager.h"

using namespace std;

int test_main() {

    //manager
    
    //vector<int> capacities = { 2, 1 };
    //vector<bool> priorityFlags = { true, false };

    //ParkingLot lot(capacities, priorityFlags, 15);

    //PrioprityManager manager(lot);

    //manager.addCar(777, true, 1.05);
    //manager.addCar(123, false, 1.08);
    //manager.addCar(444, true, 2.03);
    //manager.addCar(456, false, 2.05);


    //manager.showWaitingZone();
    //lot.showAllLanes();


    //parking lot
    
    //vector<int> capacities = { 2, 1 };
    //vector<bool> priorityFlags = { true, false };

    //ParkingLot lot(capacities, priorityFlags, 15);

    //lot.parkCar(999, 1.06, true);
    //lot.parkCar(777, 1.08, true);
    //lot.parkCar(456, 2.06, false);

    //lot.removeCar(999, 4.06);

    //lot.showAllLanes();

    //lot.~ParkingLot();



    //test whole project
    //// === create parking ===
    //vector<int> capacities = { 2, 1 };
    //vector<bool> priorityFlags = { true, false };

    //ParkingLot lot(capacities, priorityFlags, 5.0);
    //PrioprityManager manager(lot);

    //cout << "\n=== ADDING CARS ===\n";
    //manager.addCar(101, true, 1.0);
    //manager.addCar(102, true, 2.0);

    //manager.addCar(103, false, 3.0);

    //manager.addCar(104, true, 4.0);
    //manager.addCar(105, false, 5.0);

    //manager.showWaitingZone();
    //lot.showAllLanes();

    //// === delete car from top ===
    //cout << "\n=== REMOVE CAR 102 (top of lane0) ===\n";
    //lot.removeCar(102, 10.0);

    //// try to park car
    //manager.tryFillFromWaiting();

    //manager.showWaitingZone();
    //lot.showAllLanes();


    //// === delete car from bottom ===
    //cout << "\n=== REMOVE CAR 101 (middle in lane0) ===\n";
    //lot.removeCar(101, 15.0);

    //// try park car
    //manager.tryFillFromWaiting();

    //manager.showWaitingZone();
    //lot.showAllLanes();

    return 0;
}