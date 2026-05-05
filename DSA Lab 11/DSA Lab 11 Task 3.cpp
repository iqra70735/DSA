#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    if (n == 0) return -1; // Base case

    if (arr[n-1] == x) return n-1; // Found at last position

    return linearSearch(arr, n-1, x); // Recursive call
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = linearSearch(arr, n, x);

    if (result == -1)
        cout << "Element not present";
    else
        cout << "Element found at index " << result;
}
