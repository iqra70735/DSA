#include <iostream>
using namespace std;

class Node {
public:
    double rainfall;
    int day;
    Node* next;
    Node* prev;
    
    Node(double rain, int dayNum) {
        rainfall = rain;
        day = dayNum;
        next = prev = NULL;
    }
};

class RainfallList {
private:
    Node* head;
    Node* tail;
    int nodeCount;
    
public:
    RainfallList() {
        head = tail = NULL;
        nodeCount = 0;
    }
    
    void addNode(double rain, int dayNum) {
        Node* newNode = new Node(rain, dayNum);
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        nodeCount++;
    }
    
    double getValidRainfall(int dayNum) {
        double rain;
        
        do {
            cout << " Enter rainfall for Day " << dayNum << " (in mm): ";
            cin >> rain;
            
            if (rain < 0) {
                cout << " Invalid input! Rainfall cannot be negative. Please enter a non-negative value.\n";
            }
        } while (rain < 0);
        
        return rain;
    }
    
    void initializeRainfall() {
        cout << "\n ===== Rainfall Data Entry for 7 Days =====\n";
        
        for (int day = 1; day <= 7; day++) {
            double rain = getValidRainfall(day);
            addNode(rain, day);
        }
    }
    
    double calculateTotal() {
        double total = 0;
        Node* current = head;
        
        while (current != NULL) {
            total += current->rainfall;
            current = current->next;
        }
        
        return total;
    }
    
    double calculateAverage(double total) {
        return total / nodeCount;
    }
    
    int findHighestDay(double& highestRain) {
        if (head == NULL) 
		return -1;
        
        Node* current = head;
        highestRain = current->rainfall;
        int highestDay = current->day;
        
        while (current != NULL) {
            if (current->rainfall > highestRain) {
                highestRain = current->rainfall;
                highestDay = current->day;
            }
            current = current->next;
        }
        
        return highestDay;
    }
    
    int findLowestDay(double& lowestRain) {
        if (head == NULL) 
		return -1;
        
        Node* current = head;
        lowestRain = current->rainfall;
        int lowestDay = current->day;
        
        while (current != NULL) {
            if (current->rainfall < lowestRain) {
                lowestRain = current->rainfall;
                lowestDay = current->day;
            }
            current = current->next;
        }
        
        return lowestDay;
    }
    
    double getRainfallAfter5th() {
        if (nodeCount < 6) {
            cout << " Warning: List has less than 6 nodes!\n";
            return -1;
        }
        
        Node* current = head;
        int count = 1;
        
        while (count < 5 && current != NULL) {
            current = current->next;
            count++;
        }
        
        if (current != NULL && current->next != NULL) {
            return current->next->rainfall;
        } else {
            cout << " No node exists after the 5th node!\n";
            return -1;
        }
    }
   
    void displayRainfall() {
        cout << "\n ===== Weekly Rainfall Data =====\n";
        cout << " Day \t Rainfall (mm) \n ";
        cout << " -----------------------------\n";
        
        Node* current = head;
        while (current != NULL) {
            cout << " Day " << current->day << "\t" << current->rainfall<<" mm" << endl;
            current = current->next;
        }
        cout << "\n \t \t \t \t \t -----------------------------\n";
    }
    
    void displayStatistics() {
        if (head == NULL) {
            cout << " No data available!\n ";
            return;
        }
        
        double total = calculateTotal();
        double average = calculateAverage(total);
        double highestRain, lowestRain;
        int highestDay = findHighestDay(highestRain);
        int lowestDay = findLowestDay(lowestRain);
        double after5thRain = getRainfallAfter5th();
        
        cout << "\n ========== WEEKLY RAINFALL STATISTICS ==========\n";
        cout << " Total rainfall for the week: " << total << " mm\n";
        cout << " Average weekly rainfall: " << average << " mm\n";
        cout << " Day with highest rainfall: Day " << highestDay << " (" << highestRain << " mm)\n";
        cout << " Day with lowest rainfall: Day " << lowestDay << " (" << lowestRain << " mm)\n";
        
        if (after5thRain >= 0) {
            cout << " Rainfall on day after 5th node: " << after5thRain << " mm (Day 6)\n";
        }
        cout << "\n \t \t \t \t \t ================================================\n";
    }
    
    ~RainfallList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    RainfallList weekRainfall;
    int choice;
    
    cout << "\t \t \t \t \t ========== RAINFALL TRACKING SYSTEM ==========\n";
    cout << "  \t \t \t \t \t This program tracks rainfall for 7 days.\n";
    cout << "\t \t \t \t \t ==============================================\n";
    
    do {
        cout << "\n ========== MENU ==========\n";
        cout << " 1. Enter rainfall data for 7 days\n";
        cout << " 2. Display all rainfall data\n";
        cout << " 3. Display weekly statistics\n";
        cout << " 4. Exit\n";
        cout << " Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                weekRainfall.initializeRainfall();
                weekRainfall.displayRainfall();
                break;
                
            case 2:
                weekRainfall.displayRainfall();
                break;
                
            case 3:
                weekRainfall.displayStatistics();
                break;
                
            case 4:
                cout << "\n Thank you for using the Rainfall Tracking System!\n";
                cout << " Goodbye!\n";
                break;
                
            default:
                cout << " Invalid choice! Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);
    
    return 0;
}