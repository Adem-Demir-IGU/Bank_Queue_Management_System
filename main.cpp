#include<iostream>
#include<string>
using namespace std;

const int MAX = 10;
string queue[MAX];
int front = -1;
int rear = -1;
int tokenNumber = 1;
int servedCount = 0;

void enqueue(){
    if (rear == MAX - 1){
        cout << "\nQueue is full! No more tokens can be issued right now.";
        return;
    }
    string name;
    cout << "\nEnter customer name: ";
    cin.ignore();
    getline(cin, name);

    if (front == -1 && rear == -1){
        front = 0;
        rear = 0;
    }
    else {
        rear = rear + 1;
    }
    queue[rear] = "Token #" + to_string(tokenNumber) + " - " + name;
    cout << "\n" << queue[rear] << " added to the queue.";
    tokenNumber++;
}

void dequeue(){
    if (front == -1 && rear == -1){
        cout << "\nQueue is empty! No customers waiting.";
        return;
    }
    cout << "\nNow serving: " << queue[front];
    servedCount++;

    if (front == rear){
        front = -1;
        rear = -1;
    }
    else {
        front = front + 1;
    }
}

void display(){
    if (front == -1 && rear == -1){
        cout << "\nQueue is empty! No customers waiting.";
        return;
    }
    cout << "\n--- Current Queue ---";
    cout << "\nCustomers waiting: " << (rear - front + 1);
    for (int i = front; i <= rear; i++){
        cout << "\n" << (i - front + 1) << ". " << queue[i];
    }
}

void stats(){
    cout << "\n--- Statistics ---";
    cout << "\nCustomers served today: " << servedCount;
    int waiting = (front == -1) ? 0 : (rear - front + 1);
    cout << "\nCustomers currently waiting: " << waiting;
    cout << "\nNext token number: " << tokenNumber;
}

int main(){
    int choice;
    cout << "*** BANK QUEUE MANAGEMENT SYSTEM ***";
    do {
        cout << "\n\n*** MAIN MENU ***";
        cout << "\n1. New Customer Arrives (Enqueue)";
        cout << "\n2. Serve Next Customer (Dequeue)";
        cout << "\n3. Display Waiting Queue";
        cout << "\n4. Show Statistics";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: stats();
                    break;
            case 5: cout << "\nClosing the bank... Goodbye!";
                    exit(0);
            default: cout << "\nInvalid choice... Please try again!";
        }
    } while(choice != 5);
    return 0;
}
