#include <iostream>
#include <string>
using namespace std;

class Inventory{
	private:
		int serialNum;
		int manufactYear;
		int lotNum;
	public:
		Inventory(){
        	serialNum = 0;
        	manufactYear = 0;
        	lotNum = 0;
    	}
		Inventory(int s, int y, int l){
			serialNum = s;
			manufactYear = y;
		    lotNum = l;
		}
		
		int getSerialNum(){
			return serialNum;
		}
		int ManufactYear(){
			return manufactYear;
		}
		int getLotNum(){
			return lotNum;
		}
		
		void setSerialNum(int s){
			serialNum = s;
		}
		void setManufactYear(int y){
			manufactYear = y;
		}	
		void setLotNum(int l){
			lotNum = l;
		}
		
		void display(){
			cout<<" Serial Number: "<<serialNum<<endl;
			cout<<" Manufacture Year: "<<serialNum<<endl;
			cout<<" Lot Number: "<<serialNum<<endl;
		}
		
};
class Node{
	public:
		Inventory data;
		Node* link;
		
		Node(Inventory inv){
			data = inv;
			link = NULL;
		}		
};
class Stack{
	private:
		Node* top;
	public:
		Stack(){
			top = NULL;
		}
		
		void push(Inventory inv){
			Node* temp = new Node(inv);
			
			if (!temp){
         	    cout<<"\n Stack Overflow! Cannot push." << endl;
          	    return;
        	}
        	else{
        		temp->link = top;
        		top = temp;
        		cout<<"\n Part added to Inventory Successfully! "<<endl;
			}
		}
		
		void pop() {
        	if (top == NULL) {
          	  cout<<"\n Stack Underflow! No parts to take." << endl;
          	  return;
       	   }
        	else {
            	Node* temp = top;
            	cout<<"\n --- Taking part from inventory ---" << endl;
    	        cout<<" Removed part: ";
        	    top->data.display();
            	top = top->link;
            	delete temp;
        	}
    	}
		
		bool isEmpty(){
			return top == NULL;
		}
		
		void displayAll(){
			Node* temp;
			if(top == NULL){
				cout<<" No parts remaining in Inventory. "<<endl;
				return;
			}
			else{
				temp = top;
				cout<<"\n ===== Contents of All Objects Remaining on the Stack ====="<<endl;
				int count = 1;
				while (temp != NULL){
					cout<<count++<<". ";
					temp->data.display();
					temp = temp->link;
				}
				cout<<" ============================================================"<<endl;
			}
		}
};
int main(){
	Stack inventoryStack;
	
	int choice;
	char userFinished;
	
	cout<<"\n\t \t \t \t \t ============== Inventory Management System ============= \n"<<endl;
	
	 do {
        cout<<"\n ----------------------------------------" << endl;
        cout<<"  What would you like to do?" << endl;
        cout<<" 1. Add a part to inventory" << endl;
        cout<<" 2. Take a part from inventory" << endl;
        cout<<" Enter your choice (1 or 2): ";
        cin>>choice;
        
        if(choice == 1){
        	int serial, year, lot;
            cout<<"\n --- Add New Part ---" << endl;
            cout<<" Enter serial number: ";
            cin>>serial;
            cout<<" Enter manufacture year: ";
            cin>>year;
            cout<<" Enter lot number: ";
            cin>>lot;
            
            Inventory newPart(serial, year, lot);
            inventoryStack.push(newPart);
        }
        else if (choice == 2){
        	inventoryStack.pop();
        }
        else {
            cout<<"\n Invalid choice! Please enter 1 or 2. " << endl;
        }
        cout<<"\n Are you finished? (y/n): ";
        cin>>userFinished;
        
    }while(userFinished == 'n' || userFinished == 'N');
    
    cout<<"\n ================================================"<< endl;
    cout<<"\n Program finished!" << endl;
    cout<<"\n Displaying the contents of all objects that remain on the stack: " << endl;
    inventoryStack.displayAll();
    
    return 0;      	
}
