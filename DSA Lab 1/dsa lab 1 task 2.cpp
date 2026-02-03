#include <iostream>
using namespace std;
int main(){
	int n ;
	cout << " Enter the Number of Elements: ";
	cin>>n;
	
	int arr[n];
	cout<<" Enter the "<< n <<" Elements of Array:  "<<endl;
	for( int i = 0 ; i < n ; i++ ){
		cin>>arr[i];
	}
	
	for ( int i = 0 ; i< n / 2 ; i++){
		int temp = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1-i]= temp;
	}
	for (int i = 0 ; i < n ; i++){
		cout<< " "<< arr[i] << " ";
	}
	return 0 ;
}