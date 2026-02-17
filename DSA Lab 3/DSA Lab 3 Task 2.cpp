#include <iostream>
using namespace std;

int main() {
    char* ch = new char;
    cout << "\n Enter a character: ";
    cin >> *ch;
    
    cout << "\n Stored character : " << *ch << endl;
    cout << " Memory address : " << static_cast<void*>(ch) << endl;
    
    delete ch;
    
    ch = nullptr;
    if (ch == nullptr) {
        cout << " \n Memory successfully deallocated and pointer set to nullptr" << endl;
    }
    return 0;
}