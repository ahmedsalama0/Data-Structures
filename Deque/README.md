# Deque Usage Example

# Train Scheduling Simulation Using Deque in C++

This C++ project simulates a basic train scheduling system using a `deque` (double-ended queue). The program handles train arrivals from two directions: C and A. The trains from C are added to the back of the `deque`, while those from A are added to the front.

## How It Works

1. The user enters the train numbers arriving from C and A.
2. Trains arriving from A are added to the front, while those from C are added to the back.
3. The program continues until both inputs are zero, indicating no more trains are arriving.
4. Trains are then dispatched, with those at the front going to A and those at the back going to C.
