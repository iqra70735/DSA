#include <iostream>
using namespace std;

class ParkingQueue {
private:
    int *arr;
    int front, rear, size;

public:

    ParkingQueue(int s = 5) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }
	 
	    bool isFull() {
        return ((rear + 1) % size == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enterCar(int car) {
        if (isFull()) {
            cout << " Parking FULL! Car " << car << " must wait.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = car;
        cout << " Car " << car << " entered parking.\n";
    }

    void leaveCar() {
        if (isEmpty()) {
            cout << " Parking EMPTY!\n";
            return;
        }

        cout << " Car " << arr[front] << " left parking.\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << " Parking is empty\n";
            return;
        }

        cout << "  Cars in parking: ";

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    int countCars() {
        if (isEmpty()) return 0;

        int i = front, count = 0;

        while (true) {
            count++;
            if (i == rear) break;
            i = (i + 1) % size;
        }
        return count;
    }
};

int main() {
    ParkingQueue p(5);
    int choice, car;

    while (true) {
        cout << "\n ===== PARKING SYSTEM MENU ===== \n";
        cout << "1. Enter Car\n";
        cout << "2. Leave Car\n";
        cout << "3. Display Cars\n";
        cout << "4. Count Cars\n";
        cout << "5. Exit\n";
        cout << " Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Car Number: ";
            cin >> car;
            p.enterCar(car);
            break;

        case 2:
            p.leaveCar();
            break;

        case 3:
            p.display();
            break;

        case 4:
            cout << "Total Cars: " << p.countCars() << endl;
            break;

        case 5:
            cout << " Exiting system...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}