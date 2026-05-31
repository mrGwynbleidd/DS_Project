# Car Parking Management System

A simple C++ console-based **Data Structures project** that simulates a car parking system with multiple lanes, priority parking, a waiting zone, and temporary car movement during removal operations.

The project demonstrates how classic data structures such as **Stack**, **Queue**, and **Priority Queue** can be applied to solve a real-life parking management problem.

---

## Project Overview

This system models a parking lot where cars can enter, wait, park, and leave. The parking lot contains multiple lanes, and each lane has its own capacity. Some lanes can be marked as priority lanes for special vehicles.

When a car enters the system, it first goes through the waiting zone. If there is free space in the parking lot, the car is parked automatically. If the parking lot is full, the car remains in the waiting zone until a space becomes available.

The project is designed to show practical usage of data structures in a real-world scenario.

---

## Main Features

* Create a parking lot with multiple lanes
* Set custom capacity for each lane
* Mark lanes as normal or priority lanes
* Park normal and priority cars
* Remove cars by car ID
* Use a temporary queue when cars block the selected car
* Calculate parking cost based on entry and exit time
* Display the current parking lot status
* Display waiting zone status
* Demonstrate Stack, Queue, and Priority Queue operations

---

## Data Structures Used

### Stack

Each parking lane is implemented as a **Stack**.

This represents a narrow parking lane where the last car that entered is the first car that can leave.

Used in:

```cpp
SingleParkingLane(Stack).h
```

Main operations:

* `push()` — add a car to a lane
* `pop()` — remove a car from a lane
* `peek()` — display cars in the lane
* `isEmpty()` — check whether the lane is empty
* `isFull()` — check whether the lane is full

---

### Queue

A temporary queue is used when a car is blocked by other cars.

If the required car is not at the top of the stack, the system temporarily moves blocking cars into a queue and restores them later.

Used in:

```cpp
TempHoldLane(Queue).h
```

Main operations:

* `enqueue()` — add a car to the temporary queue
* `dequeue()` — remove a car from the queue
* `popBack()` — restore cars in correct order
* `showQueue()` — display temporary queue

---

### Priority Queue

The waiting zone is implemented using separate queues for priority and normal cars.

Priority cars are processed before normal cars.

Used in:

```cpp
WaitingZone(PriprityQueue).h
```

Main operations:

* `enqueue()` — add a car to the waiting zone
* `dequeue()` — remove the next car from the waiting zone
* `show()` — display waiting cars
* `isEmpty()` — check whether the waiting zone is empty

---

## Project Structure

```text
DS_Project/
│
├── DS_Project.cpp
├── ParkingLot.h
├── PriorityParkingManager.h
├── SingleParkingLane(Stack).h
├── TempHoldLane(Queue).h
├── WaitingZone(PriprityQueue).h
└── test.cpp
```

### File Descriptions

| File                           | Description                                                                          |
| ------------------------------ | ------------------------------------------------------------------------------------ |
| `DS_Project.cpp`               | Main file of the program. Contains the console menu and user interaction.            |
| `ParkingLot.h`                 | Manages parking lanes, car parking, car removal, cost calculation, and lane display. |
| `PriorityParkingManager.h`     | Connects the parking lot with the waiting zone and controls the parking process.     |
| `SingleParkingLane(Stack).h`   | Implements one parking lane using a stack based on linked list nodes.                |
| `TempHoldLane(Queue).h`        | Implements a temporary queue used while removing blocked cars.                       |
| `WaitingZone(PriprityQueue).h` | Implements the waiting zone using priority and normal queues.                        |
| `test.cpp`                     | Contains commented test cases for checking different parts of the project.           |

---

## How the System Works

1. The user enters the number of parking lanes.
2. The user sets the capacity of each lane.
3. The user marks each lane as priority or normal.
4. Cars enter the system through the waiting zone.
5. The manager tries to move cars from the waiting zone into available parking lanes.
6. Priority cars are placed in priority lanes first.
7. If priority lanes are full, priority cars may be placed in normal lanes.
8. Normal cars can only be placed in normal lanes.
9. When a car leaves, the system searches for it in the lanes.
10. If other cars block it, they are temporarily moved to a queue and restored later.
11. The system calculates the parking cost using entry and exit time.

---

## Menu Options

When the program starts, the user can choose from the following options:

```text
1. Park Car
2. Remove Car
3. Display Car Park
4. Display Lanes Parameters
0. Exit
```

---

## Example Scenario

```text
=== Welcome to Parking Manager System ===

Enter number of lanes: 2
Enter capacity for lane 1: 2
Enter capacity for lane 2: 3

Is lane 1 Priority(t/f): t
Is lane 2 Priority(t/f): f
```

Then the user can park a car:

```text
Enter car Id: 101
Is car Priority(t/f)? t
Enter time: 1.5
```

The system adds the car to the waiting zone and then tries to park it in a suitable lane.

---

## Parking Cost Calculation

The parking cost is calculated using the following formula:

```text
Cost = (Exit Time - Entry Time) × Rate Per Hour
```

The default rate is:

```text
20.0 per hour
```

---

## How to Compile and Run

### Using g++

Open the terminal in the project folder and run:

```bash
g++ DS_Project.cpp -o parking_system
```

Then run the program:

```bash
./parking_system
```

### On Windows

```bash
g++ DS_Project.cpp -o parking_system.exe
parking_system.exe
```

---

## Requirements

* C++ compiler
* Basic terminal or command prompt
* C++11 or newer is recommended

---

## Educational Purpose

This project was created as a Data Structures assignment. Its main purpose is to demonstrate how different data structures can work together in one practical system.

The project helps understand:

* Stack behavior in real-life parking lanes
* Queue behavior in temporary car storage
* Priority Queue behavior in waiting zones
* Linked list implementation
* Dynamic memory management
* Modular C++ programming using header files
* Basic object-oriented design

---

## Possible Improvements

Future improvements may include:

* Fixing spelling in file and class names
* Adding input validation for all user inputs
* Saving parking data to a file
* Adding a graphical user interface
* Adding unit tests
* Improving memory management
* Adding more detailed reports for parked and removed cars
* Supporting different parking rates for priority and normal cars

---

## Author

Created as a Data Structures project in C++.

GitHub Repository: `mrGwynbleidd/DS_Project`

---

## License

This project is for educational purposes.
