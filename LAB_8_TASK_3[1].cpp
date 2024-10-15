#include <iostream>
using namespace std;

// Define the Node structure for the linked list
struct Node {
    int data;    // Data part of the node (integer)
    Node* next;  // Pointer to the next node
};

// Define the Queue class using a linked list
class Queue {
private:
    Node* front;   // Pointer to the front of the queue
    Node* rear;    // Pointer to the rear of the queue
    int size;      // Current size of the queue
    const int MAX_SIZE;  // Maximum size of the queue

public:
    // Constructor to initialize an empty queue with fixed size
    Queue(int max_size) : MAX_SIZE(max_size) {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() const {
        return size == MAX_SIZE;
    }

    // Function to add an element to the queue
    void addQueue(int value) {
        if (isFull()) {
            cout << "Queue overflow! Cannot add more elements." << endl;
            return;
        }

        Node* newNode = new Node;  // Create a new node
        newNode->data = value;     // Set the data
        newNode->next = nullptr;   // Set next to nullptr

        if (isEmpty()) {
            front = rear = newNode;  // If empty, front and rear point to the new node
        } else {
            rear->next = newNode;  // Add the new node at the end of the queue
            rear = newNode;        // Update the rear pointer
        }

        size++;  // Increment the size
        cout << "Added value: " << value << " to the queue." << endl;
    }

    // Function to remove an element from the front of the queue
    int removeQueue() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot remove elements." << endl;
            return -1;  // Return -1 if underflow occurs
        }

        Node* temp = front;  // Temporarily store the front node
        int value = temp->data;  // Store the data to return

        front = front->next;  // Move front to the next node
        delete temp;  // Delete the old front node
        size--;  // Decrease the size

        if (front == nullptr) {
            rear = nullptr;  // If the queue becomes empty, rear is also nullptr
        }

        return value;  // Return the removed value
    }
};

// Main function to demonstrate the queues
int main() {
    Queue queue1(5);  // First queue with size 5
    Queue queue2(5);  // Second queue with size 5
    int choice, value;

    do {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Insert into First Queue\n";
        cout << "2. Remove from First Queue and Insert into Second Queue\n";
        cout << "3. Remove from Second Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (!queue1.isFull()) {
                cout << "Enter value to insert into First Queue: ";
                cin >> value;
                queue1.addQueue(value);
            } else {
                cout << "First queue is full! Cannot insert more elements." << endl;
            }
            break;

        case 2:
            if (!queue1.isEmpty()) {
                if (!queue2.isFull()) {
                    value = queue1.removeQueue();
                    queue2.addQueue(value);
                    cout << "Moved value: " << value << " from First Queue to Second Queue." << endl;
                } else {
                    cout << "Second queue is full! Cannot move elements." << endl;
                }
            } else {
                cout << "First queue is empty! Cannot remove elements." << endl;
            }
            break;

        case 3:
            if (!queue2.isEmpty()) {
                value = queue2.removeQueue();
                cout << "Removed value: " << value << " from Second Queue." << endl;
            } else {
                cout << "Second queue is empty! Cannot remove elements." << endl;
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
