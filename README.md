# Bank Queue Management System

A simple C++ console program that simulates a bank's customer waiting line using a FIFO queue. Made while learning queues in data structures.

## How it works

Customers get a token number when they arrive and are served in the same order they came in — first in, first out. The teller calls the next customer from the front of the line.

## Features

- Add a new customer to the queue (enqueue)
- Serve the next customer (dequeue)
- Display the current waiting line
- View daily statistics (served count, people waiting, next token number)

## How to run

Compile with any C++ compiler:

```bash
g++ main.cpp -o bank
./bank
```

Or on Windows:

```bash
g++ main.cpp -o bank.exe
bank.exe
```

## Menu
