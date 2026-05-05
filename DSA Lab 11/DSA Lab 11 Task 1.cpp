#include <iostream>
using namespace std;

int search(int arr[] , int n , int x) {
	for ( int i = 0 ; i < n ; i++){
		if (arr[i] == x)
		return i;
	}
	return -1;
}

int main() {
	int tickets[] = { 13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121 };
	int n = sizeof( tickets) / sizeof(tickets[0]);
	
	int winning;
	cout<<" Enter this week's winning number: "<<endl;
	cin>>winning;
	
	int result = search( tickets, n, winning);
	
	if( result == -1)
		cout<<" Invalid number. Not a winning ticket. "<<endl;
    else
        cout<<" Congratulations! Ticket found at index "<<result<<endl;
	return 0;
}