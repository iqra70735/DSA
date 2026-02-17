#include <iostream>
using namespace std;
int main() {
    int rows, cols;
    cout << " \n Enter number of rows: ";
    cin >> rows;
    cout << " Enter number of columns: ";
    cin >> cols;
    
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    cout << "\n Enter elements of the matrix: \n"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << " Enter element at position [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    cout << "\n \t \t \t \t ========== MATRIX ==========\n"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << " "<<matrix[i][j] << "\t";
        }
        cout <<" "<< endl;
    }
    
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    matrix = nullptr;    
    cout << "\n  Memory successfully deallocated!" << endl;
    return 0;
}