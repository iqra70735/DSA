#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* last; 
    
public:
    CircularLinkedList() {
        last = NULL;
    }

    bool isEmpty() {
        return last == NULL;
    }

    void addToEmpty(int data) {
        Node* newNode = new Node(data);
        last = newNode;
        newNode->next = last;
        cout << " Added " << data << " to empty list\n";
    }

    void insertBefore(int data) {
        if (last == NULL) {
            addToEmpty(data);
            return;
        }
        
        Node* newNode = new Node(data);
        newNode->next = last->next;
        last->next = newNode;
        cout << " Inserted " << data << " at the beginning\n";
    }

    void insertAfter(int data) {
        if (last == NULL) {
            addToEmpty(data);
            return;
        }
        
        Node* newNode = new Node(data);
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
        cout << " Inserted " << data << " at the end\n";
    }

    void deleteNode(int key) {
        if (last == NULL) {
            cout << " List is empty! Cannot delete.\n";
            return;
        }
        
        Node* current = last->next;
        Node* prev = last;

        if (last == last->next && last->data == key) {
            delete last;
            last = NULL;
            cout << " Deleted " << key << " (only node)\n";
            return;
        }

        bool found = false;
        do {
            if (current->data == key) {
                found = true;
                break;
            }
            prev = current;
            current = current->next;
        } while (current != last->next);
        
        if (!found) {
            cout << " Node with value " << key << " not found!\n";
            return;
        }

        if (current == last->next && current != last) {
            last->next = current->next;
            delete current;
            cout << " Deleted " << key << " from beginning\n";
        }
        
        else if (current == last) {
            prev->next = last->next;
            last = prev;
            delete current;
            cout << " Deleted " << key << " from end\n";
        }

        else {
            prev->next = current->next;
            delete current;
            cout << " Deleted " << key << " from middle\n";
        }
    }

    void display() {
        if (last == NULL) {
            cout << " List is empty!\n";
            return;
        }
        
        Node* temp = last->next;
        cout << "\n \t Circular List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(back to start)\n"<<endl;
    }

    ~CircularLinkedList() {
        if (last == NULL) return;
        
        Node* current = last->next;
        while (current != last) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete last;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value;
    
    cout << " ========== TASK 1: CIRCULAR LINKED LIST ==========\n\n";
    
    do {
        cout << " \n--- MENU ---\n";
        cout << " 1. Insert node at beginning (Insert before)\n";
        cout << " 2. Insert node at end (Insert after)\n";
        cout << " 3. Delete a node\n";
        cout << " 4. Display list\n";
        cout << " 5. Exit\n";
        cout << " Enter choice : ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << " Enter value to insert at beginning: ";
                cin >> value;
                cll.insertBefore(value);
                cll.display();
                break;
                
            case 2:
                cout << " Enter value to insert at end: ";
                cin >> value;
                cll.insertAfter(value);
                cll.display();
                break;
                
            case 3:
                cout << " Enter value to delete: ";
                cin >> value;
                cll.deleteNode(value);
                cll.display();
                break;
                
            case 4:
                cll.display();
                break;
                
            case 5:
                cout << " Exiting ...\n";
                break;
                
            default:
                cout << " Invalid choice!\n";
        }
    } while (choice != 5);
    
    return 0;
}