#include <iostream>
using namespace std;
int main(){
	int n;
	cout << " Enter the Number of Elements : ";
	cin>>n;
	
	int array[n];
	cout<< " Enter "<< n <<" Elements of Array : ";
	for ( int i = 0 ; i < n ; i++){
		cin>>array[i];
	}
	cout<< "\n 1D Array is : "<<endl;
	for( int i = 0 ; i < n ; i++){
		cout<<array[i]<<" ";
	}
	
	int key;
	int num;
	bool found = false ;
	
	cout <<"\n Enter Element to Search : ";
	cin>>key;
	cout<<endl;
	for( int i = 0 ; i < n ; i++){
		if (array[i] ==  key) {
			cout<<" Searched Number " << key <<" found at Index number " <<i<<endl;
			cout<< " Enter new Value to Update : "<<endl;
			cin>>num;
			array[i] = num;
			found = true;
			break;
		}
	}
	if (!found){
		cout<<" Searched number not found and the value not Updated . "<<endl;
	} else {
		cout<<" Updated Array : "<<endl;
		for ( int i = 0 ; i < n ; i++ ){
			cout<< array[i]<<" ";
		}
	}
	return 0;
}