#include <iostream>
#include <string>
using namespace std;

class Node{
	public:
	string title;
	double price;
	int edition;
	int noOfPages;
	Node* link;
	
	Node(string t, double p, int e, int pages){
		title = t;
		price = p;
		edition = e;
		noOfPages = pages;
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
			
			void push(string title, double price, int edition, int noOfPages){
				Node* temp = new Node(title, price, edition, noOfPages);
				
				if(!temp){
					cout<<" Stack Overflow! "<<endl;
					exit(1);
				}
				temp->link = top;
				top = temp;
				cout<<" Book \""<<title<<"\" pushed successfully!"<<endl;
			}
			
			void pop(){
				if (top == NULL){
					cout<<" Stack Underflow! "<<endl;
					exit(1);
				}
				else{
					Node* temp = top;
					cout<<" Popped book: "<<top->title<<endl;
					top = top->link;
					free(temp);
				}
			}
			
			void peek(){
				if (top == NULL){
					cout<<" Stack is Empty! "<<endl;
					return;
				}
				else{
					cout<<"\n Peek: "<<endl;
					cout<<" Top element is: "<< top->title<<" , Price: $"<<top->price<<" , Edition: "<<top->edition<<" , Pages: "<<top->noOfPages<<endl;
				} 
			}
			
			void display(){
				Node* temp;
				if (top == NULL){
					cout<<" Stack is Empty! "<<endl;
					exit(1);
				}
				else{
					temp = top;
					cout<<"\n ===== All Books in the Stack ===== \n"<<endl;
					while(temp != NULL){
						cout<<"\n  Title: "<<temp->title<<endl;
						cout<<"  Price: $"<<temp->price<<endl;
						cout<<"  Edition: "<<temp->edition<<endl;
						cout<<"  Pages: "<<temp->noOfPages<<endl;
						
						temp= temp->link;
					}
				}
			}
};

int main(){
	Stack s;
	
	cout << " \n \t \t \t \t ========== TASK 1: BOOK STACK ========== \n" << endl; 
    cout << "  1. Pushing 5 books into the stack: \n" << endl;
    s.push("C++ Programming", 49.99, 4, 850);
    s.push("Data Structures", 59.99, 3, 720);
    s.push("Algorithms", 69.99, 2, 950);
    s.push("Operating Systems", 45.99, 5, 680);
    s.push("Computer Networks", 54.99, 3, 780);
    
    s.display();

    cout << "\n  2. Finding the top element of the stack:\n" << endl;
    s.peek();

    cout << "\n\  3. Popping 2 books from the stack:\n" << endl;
    s.pop();
    s.pop();
    
    cout << "\n\  4. Displaying all remaining books in the stack:\n" << endl;
    s.display();
    
    return 0;
}