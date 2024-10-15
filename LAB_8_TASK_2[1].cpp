
#include <iostream>
#include <string>
using namespace std;

// Define the Person class
class Person {
private:
    int per_id;       // Person ID
    string per_name;  // Person name
    int per_age;      // Person age

public:
    // Constructor
    Person() : per_id(0), per_name(""), per_age(0) {}

    // Function to input person details
    void input() {
        cout << "Enter Person ID: ";
        cin >> per_id;
        cout << "Enter Person Name: ";
        cin.ignore();  // Ignore the newline character
        getline(cin, per_name);
        cout << "Enter Person Age: ";
        cin >> per_age;
    }

    // Function to output person details
    void output() const {
        cout << "Person ID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << endl;
    }
};

// Define the Node structure for the linked list
struct Node {
    Person data;   // Data part of the node (Person object)
    Node* next;    // Pointer to the next node
};

// Define the Queue class using a linked list
class Queue {
private:
    Node* front;  // Pointer to the front of the queue
    Node* rear;   // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor to clean up the queue
    ~Queue() {
        while (!isEmpty()) {
            removeQueue();
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Function to add a person to the queue
    void addQueue(const Person& p) {
        Node* newNode = new Node;  // Create a new node
        newNode->data = p;         // Assign the person to the node
        newNode->next = nullptr;   // Set the next pointer to null

        if (isEmpty()) {
            front = newNode;  // If queue is empty, front and rear point to the new node
            rear = newNode;
        } else {
            rear->next = newNode;  // Add new node at the end of the queue
            rear = newNode;
        }
        cout << "Person added to queue." << endl;
    }

    // Function to remove a person from the queue
    void removeQueue() {
        if (isEmpty()) {
            cout << "Queue underflow! No person to remove." << endl;
            return;
        }

        Node* temp = front;  // Save the front node
        front = front->next; // Move front to the next node
        cout << "Removed person details: " << endl;
        temp->data.output(); // Display the details of the removed person
        delete temp;         // Delete the old front node

        if (front == nullptr) {  // If queue becomes empty, set rear to null as well
            rear = nullptr;
        }
    }
};

// Main function to demonstrate the queue
int main() {
    Queue personQueue;
    int choice;

    do {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Add Person to Queue\n";
        cout << "2. Remove Person from Queue\n";
        cout << "3. Check if Queue is Empty\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Person p;
            p.input();
            personQueue.addQueue(p);
            break;
        }
        case 2:
            personQueue.removeQueue();
            break;
        case 3:
            if (personQueue.isEmpty()) {
                cout << "Queue is empty." << endl;
            } else {
                cout << "Queue is not empty." << endl;
            }
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
