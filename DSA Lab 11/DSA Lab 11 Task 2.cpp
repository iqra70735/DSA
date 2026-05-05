#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x) {
    if (low > high) return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == x) return mid;
    else if (x < arr[mid]) return binarySearch(arr, low, mid - 1, x);
    else return binarySearch(arr, mid + 1, high, x);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
        cout << "Element not present";
    else
        cout << "Element found at index " << result;
}
