#include <iostream>
#include <cstring>
using namespace std;
class Book{
	private:
		string bookId;
		char bookName[100];
		double bookPrice;
		char bookAuthor[100];
		string bookISBN;
	public:
		Book(){
			bookId = "";
			strcpy(bookName , "");
			bookPrice = 0.0;
			strcpy(bookAuthor,"");
			bookISBN = "";
		}
		Book(string id , const char* name, double price , const char* author , string isbn){
			bookId = id;
			strcpy(bookName , name);
			bookPrice = price;
			strcpy(bookAuthor , author);
			bookISBN = isbn;
		}
		
		string getBookId(){
			return bookId;
		}
		char* getBookName(){
			return bookName;
		}
		double getBookPrice(){
			return bookPrice;
		}
		char* getBookAuthor(){
			return bookAuthor;
		}
		string getBookISBN(){
			return bookISBN;
		}
		
		void setBookId(string id){
			bookId = id;
		}
		void setBookName(const char* name){
			strcpy(bookName , name);
		}
		void setBookPrice(double price){
			bookPrice = price;
		}
		void setBookAuthor(const char* author){
			strcpy(bookAuthor , author);
		}
		void getBookISBN(string isbn){
			bookISBN = isbn;
		}
	void displayBook(){
		cout<<" BookId "<<bookId<<endl;
		cout<<" Book Name "<<bookName<<endl;
		cout<<" Book Price "<<bookPrice<<endl;
		cout<<" Book Author "<<bookAuthor<<endl;
		cout<<" Book ISBN "<<bookISBN<<endl;
		cout<<" \t ------------------------------------------- "<<endl;
	}	
};

class Node{
		private:
			Book book;
			Node* next;
			Node* prev;
		public:
			Node(){
				next= NULL;
				prev= NULL;
			}
			Node(string id , const char* name, double price , const char* author , string isbn)
			: book(id , name, price , author , isbn){
				next = NULL;
				prev= NULL;
			}
			
			Book getBook(){
				return book;
			}
			void setBook(Book b){
				book = b;
			}
			
			Node* getNext(){
				return next;
			}
			void setNext(Node* n){
				next = n;
			}
			
			Node* getPrev(){
				return prev;
			}
			void setPrev(Node* p){
				prev = p;
			}
};

class BookList{
	private:
		Node* head;
		int count;
	public:
		BookList(){
			head = NULL;
			count = 0;
		}
		
	void addBook(string bookId, const char* bookName, double bookPrice, const char* bookAuthor, string bookISBN){
		Node* newNode = new Node(bookId, bookName, bookPrice, bookAuthor, bookISBN);
		if(head == NULL){
			head = newNode;
			head->setNext(head);
			head->setPrev(head);
		}
		else{
			Node* last = head->getPrev();
			newNode->setNext(head);
			newNode->setPrev(last);
			last->setNext(newNode);
			head->setPrev(newNode);
		}
		count++;
		cout<<" Book Added Successfully! (ID: "<<bookId<<" ) "<<endl;
	}
	
	void removeBook(string bookId){
		if (head == NULL){
			cout<<" No Book in the List! "<<endl;
			return; 
		}
		
		Node* current = head;
		bool found = false;
		
		do{ 
			if (current ->getBook().getBookId() == bookId){
				found = true;
				break;
			}
			current = current->getNext();
		}while(current != head);	
		
	if(!found){
		cout<<" Book with ID "<<bookId<<" not found! "<<endl;
		return ;
	}
	if(head->getNext() == head && head == current) {
		delete current;
		head = NULL;
	}
	else if(current == head){
		Node* last = head->getPrev();
		Node* newHead = head->getNext();
		last->setNext(newHead);
		newHead->setPrev(last);
		head = newHead;
		delete current;
	}
	else {
		Node* prevNode = current->getPrev();
		Node* nextNode = current->getNext();
		prevNode->setNext(nextNode);
		nextNode->setPrev(prevNode);
		delete current;
	}
	count--;
	 cout<<" Book with ID " << bookId << " removed successfully! "<<endl;
	}
	
	void updateBook(string bookId, const char* bookName, double bookPrice, const char* bookAuthor, string bookISBN){
		if (head == NULL){
            cout << " No books in the list! "<<endl;
            return;
        }
        Node* current = head;
		bool found = false;
		
		do{ 
			if (current ->getBook().getBookId() == bookId){
				found = true;
				break;
			}
			current = current->getNext();
		}while(current != head);	
		
	if(!found){
		cout<<" Book with ID "<<bookId<<" not found! "<<endl;
		return ;
	}
	Book updatedBook(bookId, bookName, bookPrice, bookAuthor, bookISBN);
	current->setBook(updatedBook);
	cout<<" Book with ID "<<bookId<<" updated Successfully! "<<endl;
	}
	
	void printBooks(){
		if(head == NULL){
			cout<<" No Books in the Library! "<<endl;
			return;
		}
		cout<<"\n ================= All Books ================= \n"<<endl;
		cout<<" Total Books: "<<count<<"\n "<<endl;
		
		Node* current = head;
		int num = 1;
		
		do{
			cout<<" Book # "<<num<<" : \n "<<endl;
			current->getBook().displayBook();
			current = current->getNext();
			num++;
		}while ( current != head);
		cout<<" \n \t \t \t \t \t ==================================== \n "<<endl;
	}
	
	void printBook(string bookId){
        if (head == NULL){
            cout<<" No books in the list! "<<endl;
            return;
        }
        Node* current = head;
        bool found = false;       
        do{
            if(current->getBook().getBookId() == bookId){
                found = true;
                break;
            }
            current = current->getNext();
        }while (current != head);
         if(!found){
            cout<<" Book with ID " << bookId << " not found! "<<endl;
            return;
        }
         cout<<"\n  ========== BOOK DETAILS =========="<<endl;
        current->getBook().displayBook();
        cout<<"\n \t \t \t \t \t================================== \n "<<endl;
    }
    
    ~BookList(){
        if(head == NULL) 
		return;
        Node* current = head;
        Node* nextNode; 
        do{
            nextNode = current->getNext();
            delete current;
            current = nextNode;
        }while (current != head);
    }
};

int main(){
	BookList library;
	cout << "\n \t \t \t \t ========== TASK 3: BOOK MANAGEMENT SYSTEM ==========\n"<<endl;
	cout << "Adding 10 books to the library...\n\n";
    
    library.addBook("B001", "C++ Programming", 45.99, "Bjarne Stroustrup", "978-0-321-99278-9");
    library.addBook("B002", "Data Structures", 52.50, "Mark Weiss", "978-0-321-44146-1");
    library.addBook("B003", "Algorithms", 48.75, "Robert Sedgewick", "978-0-321-57351-3");
    library.addBook("B004", "Operating Systems", 55.00, "Andrew Tanenbaum", "978-0-13-359162-0");
    library.addBook("B005", "Database Systems", 47.25, "Abraham Silberschatz", "978-0-07-352332-3");
    library.addBook("B006", "Computer Networks", 44.99, "James Kurose", "978-0-13-285620-1");
    library.addBook("B007", "Software Engineering", 49.95, "Ian Sommerville", "978-0-13-703515-1");
    library.addBook("B008", "Artificial Intelligence", 58.50, "Stuart Russell", "978-0-13-604259-4");
    library.addBook("B009", "Machine Learning", 62.99, "Tom Mitchell", "978-0-07-042807-2");
    library.addBook("B010", "Web Development", 39.99, "Jon Duckett", "978-1-118-53764-8");
    
    library.printBooks();
    
    cout<<"\n --- Removing Books --- \n"<<endl;
    
    cout<<"\n Attempting to remove valid book (B003):\n"<<endl;
    library.removeBook("B003"); 
    
    cout<<"\n Attempting to remove invalid book (B999):\n"<<endl;
    library.removeBook("B999"); 
    library.printBooks();
    
    cout<<"\n --- Updating Book --- \n"<<endl;
    cout<<"\n Updating book B005 with new information: \n "<<endl;
    library.updateBook("B005", "Advanced Database Systems", 59.99, "Abraham Silberschatz (Updated)", "978-0-07-352332-3");
    
    cout<<"\n --- Displaying Updated Book ---\n"<<endl;
    library.printBook("B005");
    
    cout<<"\n --- Final Book List After All Operations ---\n"<<endl;
    library.printBooks();
	return 0;
}