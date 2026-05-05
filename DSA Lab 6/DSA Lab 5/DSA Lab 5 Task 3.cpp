#include <iostream>
#include <string>
using namespace std;
class Player {
public:
    string name;
    int score;
    Player* next;
    Player* prev;

    Player(string n, int s) {
        name = n;
        score = s;
        next = prev = NULL;
    }
};

class GolfTournament {
public:
    Player* head;

    GolfTournament() {
        head = NULL;
    }

    void addPlayer(string name, int score) {
        Player* newNode = new Player(name, score);

        if (head == NULL) {
            head = newNode;
            return;
        }

        if (score < head->score) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Player* temp = head;
        while (temp->next != NULL && temp->next->score < score) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void deletePlayer(string targetName) {
        if (head == NULL) return;

        Player* temp = head;
        while (temp != NULL && temp->name != targetName) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << " Player " << targetName << " not found.\n";
            return;
        }

        if (temp->prev != NULL) temp->prev->next = temp->next;
        else head = temp->next; 

        if (temp->next != NULL) temp->next->prev = temp->prev;

        delete temp;
        cout << " Player " << targetName << " deleted.\n";
    }

    void displayAll() {
        Player* temp = head;
        cout << "\n --- Player List (Sorted) ---\n";
        while (temp != NULL) {
            cout << temp->name << " (" << temp->score << ") <=> ";
            temp = temp->next;
        }
        cout << " NULL\n";
    }

    void displayLowest() {
        if (head == NULL) return;
        cout << " Lowest Score: " << head->name << " with " << head->score << endl;
    }

    void displaySameScore(int targetScore) {
        Player* temp = head;
        bool found = false;
        cout << " Players with score " << targetScore << ": ";
        while (temp != NULL) {
            if (temp->score == targetScore) {
                cout << temp->name << " ";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << " None";
        cout << endl;
    }
    
    void displayBackwardFrom(string targetName) {
        Player* temp = head;
        while (temp != NULL && temp->name != targetName) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << " Player not found.\n";
            return;
        }

        cout << " Backward from " << targetName << ": ";
        while (temp != NULL) {
            cout << temp->name << " (" << temp->score << ") ";
            temp = temp->prev; 
        }
        cout << endl;
    }
};

int main() {
    GolfTournament tournament;

    tournament.addPlayer("Ali", 72);
    tournament.addPlayer("Sara", 68);
    tournament.addPlayer("Ahmed", 75);
    tournament.addPlayer("Iqra", 68);

    tournament.displayAll();
    tournament.displayLowest();
    tournament.displaySameScore(68);
    tournament.displayBackwardFrom("Ahmed");

    tournament.deletePlayer("Sara");
    tournament.displayAll();

    return 0;
}