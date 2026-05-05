#include <iostream>
#define MAX_SIZE 5
using namespace std;

class Queue {
private:
    int myqueue[MAX_SIZE], front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if (rear == MAX_SIZE - 1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1 || front > rear) {
            return true;
        }
        return false;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << " Queue is full!! Cannot enqueue " << value << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            myqueue[rear] = value;
            cout<<" " << value << " has been enqueued successfully." << endl;
        }
    }

    int dequeue() {
        int value;
        if (isEmpty()) {
            cout << " Queue is empty!! Cannot dequeue." << endl;
            return -1;
        } else {
            value = myqueue[front];
            if (front == rear) {

                front = -1;
                rear = -1;
            } else {
                front++;
            }
            cout << " Deleted => " << value << " from the queue" << endl;
            return value;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << " Queue is Empty!!" << endl;
        } else {
            cout << " Queue elements (front to rear): ";
            for (int i = front; i <= rear; i++) {
                cout << myqueue[i] << " ";
            }
            cout << endl;
            cout << " Front index: " << front << ", Rear index: " << rear << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n \t \t \t \t ========== QUEUE MENU ==========" << endl;
        cout << " 1. Enqueue (Insert)" << endl;
        cout << " 2. Dequeue (Delete)" << endl;
        cout << " 3. Display Queue" << endl;
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