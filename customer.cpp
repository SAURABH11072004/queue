#include <iostream>
#include <string>
using namespace std;

class Customer {
    string customer_name;
    int contact;

public:
    
    void read() {
        cout << "ENTER CUSTOMER NAME: ";
        cin >> customer_name;
        cout << "ENTER CONTACT NO: ";
        cin >> contact;
    }

   
    void display() {
        cout << "CUSTOMER NAME: " << customer_name << endl;
        cout << "CUSTOMER CONTACT: " << contact << endl;
    }
};

class CircularQueue {
    Customer* queue; 
    int maxsize;
    int rear, front;

public:
    
    CircularQueue(int size) {
        maxsize = size;
        queue = new Customer[maxsize]; 
        front = rear = -1; 
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % maxsize == front;
    }

    // Check if the queue is empty
    bool isEmpty() {
    return (front == -1);  // Queue is empty if front is -1
}

    

    // Add (enqueue) a customer to the queue
    void add(Customer customer) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more customers." << endl;
        } else {
            if (front == -1) { // First customer to arrive
                front = 0;
            }
            rear = (rear + 1) % maxsize;
            queue[rear] = customer;
            cout << "Customer added to the queue." << endl;
        }
    }

    // Remove (dequeue) a customer from the queue
    void remove() {
        if (isEmpty()) {
            cout << "Queue is empty! No customers to checkout." << endl;
        } else {
            cout << "Customer checking out: ";
            queue[front].display(); // Display the customer who is checking out
            if (front == rear) { // Only one customer in the queue
                front = rear = -1; // Reset the queue
            } else {
                front = (front + 1) % maxsize;
            }
        }
    }

    // Display all customers in the queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "No customers in the queue." << endl;
        } else {
            cout << "Customers in the queue: " << endl;
            int i = front;
            while (i != rear) {
                queue[i].display();
                i = (i + 1) % maxsize;
            }
            queue[i].display(); // Display the last customer
        }
    }

   
    ~CircularQueue() {
        delete[] queue;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    CircularQueue queue(size); 

    int choice;
    do {
        cout << "\n1. Add Customer\n2. Checkout Customer\n3. View Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
           
            Customer customer;
            customer.read();
            queue.add(customer);
            break;
        }
        case 2:
            
            queue.remove();
            break;
        case 3:
          
            queue.displayQueue();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
