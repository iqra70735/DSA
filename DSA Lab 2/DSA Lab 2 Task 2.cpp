#include <iostream>
using namespace std;
void swap( int *a , int *b){
	int temp = *a ;
	*a = *b ;
	*b = temp;
}
int main(){
	int num1 , num2;
	
	cout<<"\n \t \t \t \t ======================================== "<<endl;
	cout<<" \t \t \t \t   SWAPPING TWO INTEGERS USING POINTERS "<<endl;
	cout<<" \t \t \t \t ======================================== "<<endl;
	
	cout<< "\n  Enter Two Integers to Swap: "<<endl;
	cout<< " First Integer : ";
	cin>>num1;
	cout<< " Second Integer : ";
	cin>>num2;
	
	cout<< "\n Before Swapping : "<<endl;
	cout<<" First Number : "<<num1<<endl;
	cout<<" Second Number : "<<num2<<endl;
	
	swap(&num1 , &num2);
	
	cout<<" \n After Swapping : "<<endl;
	cout<<" First Number : "<<num1<<endl;
	cout<<" Second Number : "<<num2<<endl;
	return 0;
}