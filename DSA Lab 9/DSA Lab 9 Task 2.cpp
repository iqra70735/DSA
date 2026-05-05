#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (newNode == NULL) {
            cout << " Memory allocation failed! Overflow." << endl;
            return;
        }

        if (isEmpty()) {

            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " has been enqueued successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << " Queue is empty!! Underflow. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        int deletedValue = front->data;

        if (front == rear) {

            front = rear = NULL;
        } else {
            front = front->next;
        }

        cout << deletedValue << " has been dequeued from the queue." << endl;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << " Queue is Empty!!" << endl;
            return;
        }

        Node* temp = front;
        cout << " Queue elements (front to rear): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
    }
};

int main() {
    Queue q;
    int choice, value;

    cout << "\n \t \t \t \t \t ========== QUEUE USING LINKED LIST ==========" << endl;
    cout << " Initially: ";
    q.display();

    do {
        cout << "\n \t \t ========== MENU ==========" << endl;
        cout << " 1. Enqueue (Insert at rear)" << endl;
        cout << " 2. Dequeue (Delete from front)" << endl;
        cout << " 3. Display all elements" << endl;
        cout << " 4. Exit" << endl;
        cout << " Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << " Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << " Exiting program..." << endl;
                break;

            default:
                cout << " Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}