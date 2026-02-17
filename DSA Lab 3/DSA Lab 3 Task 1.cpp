#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    string code;
    float price;
};
int main() {
    int n;
    cout << " Enter number of products: ";
    cin >> n;
    
    Product* products = new Product[n];
    
    cout << "\n Enter product details:\n"<<endl;
    for (int i = 0; i < n; i++) {
        cout << "\n Product " << i+1 << ":\n";
        cout << " Name: ";
        cin >> products[i].name;
        cout << " Code: ";
        cin >> products[i].code;
        cout << " Price: Rs";
        cin >> products[i].price;
    }
    
    cout << "\n \t \t \t========== PRODUCT LIST ==========\n"<<endl;
    for (int i = 0; i < n; i++) {
        cout << "\n Product " << i+1 << ":\n";
        cout << "  Name: " << products[i].name << endl;
        cout << "  Code: " << products[i].code << endl;
        cout << "  Price: Rs" << products[i].price << endl;
    }
    cout << "\t \t \t \t ---------------------------------\n";
    
    delete[] products;
    products = nullptr;
    
    return 0;
}