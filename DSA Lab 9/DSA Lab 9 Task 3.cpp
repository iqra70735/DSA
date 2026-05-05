#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
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
        cout << " "<<value << " has been enqueued." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << " Queue is empty!! Underflow." << endl;
            return;
        }

        Node* temp = front;
        int deletedValue = front->data;

        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
        }

        cout <<" "<< deletedValue << " has been dequeued." << endl;
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

    int count() {
        int count = 0;
        Node* temp = front;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
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

    cout << "\n \n \t \t \t \t ========== QUEUE WITH COUNT FUNCTION ==========" << endl;

    do {
        cout << "\n ========== MENU ==========" << endl;
        cout << " 1. Enqueue" << endl;
        cout << " 2. Dequeue" << endl;
        cout << " 3. Display" << endl;
        cout << " 4. Count elements" << endl;
        cout << " 5. Exit" << endl;
        cout << " Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << " Enter value: ";
                cin >> value;
                q.enqueue(value);
                cout << " Current queue size: " << q.count() << endl;
                break;

            case 2:
                q.dequeue();
                cout << " Current queue size: " << q.count() << endl;
                break;

            case 3:
                q.display();
                cout << " Queue size: " << q.count() << endl;
                break;

            case 4:
                cout << " Number of elements in queue: " << q.count() << endl;
                break;

            case 5:
                cout << " Exiting program..." << endl;
                break;

            default:
                cout << " Invalid choice!" << endl;
        }
    } while (choice != 5);
    return 0;
}