#include <iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node* prev;
	
	Node(int val){
		data= val;
		next = prev = NULL;
	}
};
class DoublyList{
	public:
	Node* head;
	Node* tail;
	
	DoublyList(){
		head = tail = NULL;
	}
	
	void addAtBeginning(int val){
		Node* newNode = new Node(val);
		if( head == NULL){
			head = tail = newNode;
		}else{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	
	void addAfterValue(int target , int val){
		Node* temp = head;
		while(temp != NULL && temp->data != target){
			temp = temp->next;
		}
		if (temp == NULL){
			return ;
		}
		
		Node* newNode = new Node(val);
		newNode->next = temp->next;
		newNode->prev= temp;
		if(temp->next != NULL){
			temp->next->prev = newNode;
		}else{
			tail = newNode;
		}
		temp->next = newNode;
	}
	
	void deleteAtBeginning(){
		if( head == NULL){
			return ;
		}
		
		Node* temp = head;
		head = head->next;
		if(head != NULL){
			head->prev = NULL;
		}else{
			tail = NULL;
		}
		temp->next =NULL;
		delete temp;
	}
	
	void deleteAfterValue(int target){
		Node* temp = head;
		while( temp != NULL && temp->data != target){
			temp = temp->next;
		}
		if (temp == NULL || temp->next == NULL){
			return;
		}
		
		Node* toDelete = temp->next;
		temp->next = toDelete->next;
		if(toDelete->next != NULL){
			toDelete->next->prev =temp;
		}else{
			tail = temp;
		}
		delete toDelete;
	}
	void print(){
		Node* temp = head;
		while(temp != NULL){
			cout<<temp->data<<" <=> ";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}
	 
};
int main(){
	DoublyList dll;
	int n ;
	int val;
	cout<<" How many marks you want to enter in Marks List: ";
	cin>>n;
	cout<<endl;
	for(int i = 0 ; i < n ; i++){
		cout<<" Enter Marks "<<i+1<<" : ";
		cin>>val;
		
		Node* newNode = new Node(val);
		if(dll.head == NULL){
			dll.head = dll.tail = newNode;
		}else {
			dll.tail->next = newNode;
			newNode->prev = dll.tail;
			dll.tail = newNode;
		}
	}
	dll.print();
	dll.addAtBeginning(1);
	cout<<" List After adding a Value at Beginning : "<<endl;
	dll.print();
	dll.addAfterValue(45, 60);
	cout<<" List After adding a Value after 45 : "<<endl;
	dll.print();
	dll.deleteAtBeginning();
	cout<<" List After Deleting a Value from the Beginning : "<<endl;
	dll.print();
	dll.deleteAfterValue(45);
	cout<<" List After Deleting a Value after 45 : "<<endl;
	dll.print();
	return 0;
}