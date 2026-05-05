#include <iostream>
#include <string>
using namespace std;

struct EmployeeNode{
    string name;
    EmployeeNode* next;
    
    EmployeeNode(const string& empName){
        name = empName;
        next = NULL;
    }
};
class EmployeeList{
private:
    EmployeeNode* last;
    int count;
    
public:
    EmployeeList(){
        last = NULL;
        count = 0;
    }

    void addEmployee(const string& name){

        if (searchEmployee(name)){
            cout << " \n Employee \"" << name << "\" already exists! Cannot add.\n";
            return;
        }
        
        EmployeeNode* newNode = new EmployeeNode(name);
        
        if (last == NULL){
            last = newNode;
            newNode->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        
        count++;
        cout << " \n Employee \"" << name << "\" added successfully!\n";
    }

    void deleteEmployee(const string& name){
        if (last == NULL) {
            cout << " \n List is empty! No employees to delete.\n";
            return;
        }
        
        EmployeeNode* current = last->next;
        EmployeeNode* prev = last;

        bool found = false;
        do{
            if (current->name == name){
                found = true;
                break;
            }
            prev = current;
            current = current->next;
        }while (current != last->next);
        
        if (!found) {
            cout << " \n Employee \"" << name << "\" not found!\n";
            return;
        }

        if (last == last->next) {
            delete last;
            last = NULL;
        }

        else if (current == last->next) {
            last->next = current->next;
            delete current;
        }

        else if (current == last) {
            prev->next = last->next;
            last = prev;
            delete current;
        }

        else {
            prev->next = current->next;
            delete current;
        }
        
        count--;
        cout << " \n Employee \"" << name << "\" deleted successfully!\n";
    }

    void updateEmployee(const string& oldName, const string& newName) {
        if (last == NULL) {
            cout << "\n List is empty! Cannot update.\n";
            return;
        }
        
        EmployeeNode* current = last->next;
        bool found = false;
        
        do {
            if (current->name == oldName) {
                found = true;
                break;
            }
            current = current->next;
        } while (current != last->next);
        
        if (!found) {
            cout << " \n Employee \"" << oldName << "\" not found!\n";
            return;
        }

        EmployeeNode* check = last->next;
        bool nameExists = false;
        do {
            if (check->name == newName && check != current) {
                nameExists = true;
                break;
            }
            check = check->next;
        } while (check != last->next);
        
        if (nameExists) {
            cout << " \n Employee \"" << newName << "\" already exists! Cannot update.\n";
            return;
        }
        
        current->name = newName;
        cout << " \n Employee updated from \"" << oldName << "\" to \"" << newName << "\" successfully!\n";
    }

    bool searchEmployee(const string& name){
        if (last == NULL) return false;
        
        EmployeeNode* current = last->next;
        do {
            if (current->name == name) {
                return true;
            }
            current = current->next;
        } while (current != last->next);
        
        return false;
    }

    void searchAndDisplay(const string& name) {
        if (searchEmployee(name)) {
            cout << " \n Employee \"" << name << "\" found successfully!\n";
        } else {
            cout << "\n Employee \"" << name << "\" not found!\n";
        }
    }

    void displayAll(){
        if (last == NULL) {
            cout << " \n No employees in the list!\n";
            return;
        }
        
        cout << "\n ========== EMPLOYEE LIST ==========\n";
        EmployeeNode* current = last->next;
        int num = 1;
        do {
            cout << num << ". " << current->name << endl;
            current = current->next;
            num++;
        } while (current != last->next);
        cout << "\n Total employees: " << count << endl;
        cout << " ===================================\n";
    }
    
    ~EmployeeList() {
        if (last == NULL) 
		return;
        
        EmployeeNode* current = last->next;
        while (current != last) {
            EmployeeNode* temp = current;
            current = current->next;
            delete temp;
        }
        delete last;
    }
};

int main(){
    EmployeeList empList;
    int choice;
    string name, newName;
    
    cout << "\n \t \t \t \t ========== TASK 2: DATA ENTRY OPERATOR ==========\n";
    cout << "\n \t \t Employee Management System (Circular Singly Linked List)\n\n";

    empList.addEmployee("Ali");
    empList.addEmployee("Sara");
    empList.addEmployee("Usman");
    empList.addEmployee("Fatima");
    
    do{
        cout << "\n --- MENU ---\n";
        cout << " 1. Add Employee\n";
        cout << " 2. Delete Employee\n";
        cout << " 3. Update Employee\n";
        cout << " 4. Search Employee\n";
        cout << " 5. Display All Employees\n";
        cout << " 6. Exit\n";
        cout << " Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice){
            case 1:
                cout << " Enter employee name: ";
                getline(cin, name);
                empList.addEmployee(name);
                break;
                
            case 2:
                cout << " Enter employee name to delete: ";
                getline(cin, name);
                empList.deleteEmployee(name);
                break;
                
            case 3:
                cout << " Enter employee name to update: ";
                getline(cin, name);
                cout << " Enter new name: ";
                getline(cin, newName);
                empList.updateEmployee(name, newName);
                break;
                
            case 4:
                cout << " Enter employee name to search: ";
                getline(cin, name);
                empList.searchAndDisplay(name);
                break;
                
            case 5:
                empList.displayAll();
                break;
                
            case 6:
                cout << " Exiting Employee Management System...\n";
                break;
                
            default:
                cout << " Invalid choice!\n";
        }
    } while (choice != 6);
    
    return 0;
}