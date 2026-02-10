#include <iostream>
using namespace std;
int main (){
	int arr[5];
	cout<< " Enter the Array of  5 Elements : "<<endl;
	for ( int i = 0 ; i < 5 ; i++){
		cin>>arr[i];
	}
	int* p = arr;
	cout << " Displaying Array elements using Pointer Iteration : " << endl;
	for ( int i = 0 ; i < 5 ; i++){
		cout<<" "<<*(p + i)<< " ";
	}
	
	return 0;
}