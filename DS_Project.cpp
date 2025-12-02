// DS_Project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"SingleParkingLane(Stack).h"
#include"TempHoldLane(Queue).h"
#include"ParkingLot.h"
#include"WaitingZone(PriprityQueue).h"
#include"PriorityParkingManager.h"

using namespace std;

int main()
{
    //MENU

    vector<int> capacity;
    vector<bool> priority;
    int n;

    cout << "=== Welcome to Parking Manager System ===\n\n";

    cout << "Enter number of lanes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cout << "Enter capacity for lane " << i + 1 << " : ";
        cin >> num;
        capacity.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        bool pr;
        char p;
        cout << "Is lane " << i + 1 << " Priority(t/f): ";
        cin >> p;
        if (p == 't') {
            pr = true;
        }
        else if (p == 'f') {
            pr = false;
        }
        else {
            cout << "Invalid input!";
            break;
        }
        priority.push_back(pr);
    }

    ParkingLot lot(capacity, priority);
    PrioprityManager manager(lot);

    cout << "\nLanes:\n";
    for (int i = 0; i < n; i++) {
        cout << "For lane " << i + 1 << " capacity : " << capacity[i] << ", Is Priority(1/0): " << priority[i] << endl;
    }


    int choice = -1;
    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Park Car\n";
        cout << "2. Remove Car\n";
        cout << "3. Display Car Park\n";
        cout << "4. Display Lanes Parameters\n";
        cout << "0. Exit\n";



        cout << "Enter your choice: ";
        cin >> choice;



        switch (choice)
        {
        case 1:
            int id;
            bool isPriority;
            char p;
            double t;

            cout << "Enter car Id: ";
            cin >> id;
            cout << "Is car Priority(t/f)? ";
            cin >> p;

            if (p == 't') {
                isPriority = true;
            }
            else if (p == 'f') {
                isPriority = false;
            }
            else {
                cout << "Invalid input!";
                break;
            }

            cout << "Enter time: ";
            cin >> t;

            manager.addCar(id, isPriority, t);

            break;
        case 2:
            int carId;
            double time;
            cout << "Enter car Id to remove: ";
            cin >> carId;

            cout << "Enter exit time: ";
            cin >> time;

            lot.removeCar(carId, time);
            manager.tryFillFromWaiting();


            break;

        case 3:
            cout << "\nParking\n";
            manager.showWaitingZone();
            lot.showAllLanes();

            break;

        case 4:
            cout << "\nLanes:\n";
            for (int i = 0; i < n; i++) {
                cout << "For lane " << i + 1 << " capacity : " << capacity[i] << ", Is Priority(1/0): " << priority[i] << endl;
            }

            break;
        default:
            cout << "Invalid input\n";
            break;
        }


    } while (choice != 0);
    return 0;

    lot.~ParkingLot();
    manager.~PrioprityManager();
    capacity.clear();
    priority.clear();


}