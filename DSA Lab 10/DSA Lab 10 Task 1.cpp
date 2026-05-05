#include <iostream>
using namespace std;
const int SIZE = 5;

class CircularQueue {
	private:
		int arr[SIZE];
		int front , rear , count;
		
	public:
		CircularQueue() {
			front = rear = count = 0;
		}
		
		bool isEmpty() {
			return ( count == 0);
		}
		
		bool isFull() {
			return ( count == SIZE);
		}
		
		void enqueue( int value ) {
			if ( isFull()){
				cout<< " Queue OverFlow , cannot insert "<<value<<endl;
			}
			arr[rear] = value;
			rear = (rear + 1) % SIZE;
			count++;
			displayState(" Enqueue "+ to_string(value));
		}
		
		void deQueue(){
			if(isEmpty()){
				cout<<" Queue UnderFlow , cannot Delete "<<endl;
			}
			
			int value = arr[front];
			front = (front + 1) % SIZE;
			count --;
			displayState(" Dequeue "+ to_string(value));
		}
		int getFront() {
			if( isEmpty())
			return -1;
			
			return arr[front];
		}
		
		int getRear() {
			if( isEmpty())
			return -1;
			
			return  arr[(rear -1 + SIZE ) % SIZE];
		}
		
		void displayState( string action ){
			cout<< " Action: "<<action<<endl;
			cout<<" Front Value: "<<(isEmpty() ? -1 : getFront())<<endl;
			cout<<" Rear Value: "<<(isEmpty() ? -1 : getRear())<<endl;
			cout<<" Array State: ";
			if(isEmpty()){
				cout<<" Empty "<<endl;
			}
			else{
				int i = front;
				for( int c = 0 ; c < count ; c++){
					cout<<" "<<arr[i]<<" ";
					i = ( i + 1 ) % SIZE;
				}
				cout<<endl;
			}
		}
};
int main() {
	CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.deQueue();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    
	return 0;
}
