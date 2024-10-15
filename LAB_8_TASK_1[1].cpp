#include <iostream>
#include <string>
using namespace std;

// Define the Student class
class Student {
private:
    int reg_no;    // Registration number
    string st_name; // Student name
    float cgpa;    // CGPA

public:
    // Constructor
    Student() : reg_no(0), st_name(""), cgpa(0.0) {}

    // Function to input student details
    void input() {
        cout << "Enter Registration No: ";
        cin >> reg_no;
        cout << "Enter Student Name: ";
        cin.ignore(); // To ignore the newline left in the input buffer
        getline(cin, st_name);
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    // Function to output student details
    void output() const {
        cout << "Registration No: " << reg_no << ", Student Name: " << st_name << ", CGPA: " << cgpa << endl;
    }
};


class Stack {
private:
    Student* arr;  // Pointer to dynamic array
    int top;       // Index of the top element
    int capacity;  

public:
    // Constructor to create a stack of given size
    Stack(int size) {
        arr = new Student[size]; // Dynamic array allocation
        capacity = size;
        top = -1;
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Function to push a student object onto the stack
    void push(const Student& s) {
        if (top == capacity - 1) {
            cout << "Stack overflow! Cannot push more elements." << endl;
            return;
        }
        arr[++top] = s; 
    }

 
    void pop() {
        if (top == -1) {
            cout << "Stack underflow! Cannot pop any elements." << endl;
            return;
        }
        cout << "Popped student details: " << endl;
        arr[top--].output(); 
    }


    bool isEmpty() const {
        return top == -1;
    }


    bool isFull() const {
        return top == capacity - 1;
    }
};

int main() {
    int size;


    cout << "Enter the size of the stack: ";
    cin >> size;

    
    Stack studentStack(size);


    for (int i = 0; i < size; ++i) {
        cout << "Enter details for student " << i + 1 << ": " << endl;
        Student s;
        s.input();
        studentStack.push(s);
    }

    cout << "\nPopping all students from the stack:\n";
    while (!studentStack.isEmpty()) {
        studentStack.pop();
    }

    return 0;
}

