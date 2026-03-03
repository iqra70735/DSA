#include <iostream>
using namespace std;
struct MobileStore{
	string brandName;
	int units;
	float price;
	MobileStore* next;
};

MobileStore* head = NULL;

void addMobile(string brandName, int units, float price){
	MobileStore* newMobilesStore = new MobileStore();
	newMobilesStore->brandName = brandName;
	newMobilesStore->units = units;
	newMobilesStore->price = price;
	newMobilesStore->next = head;
	head = newMobilesStore;
}

void deleteMobile(string brandName){
	if(head == NULL){
		cout<<" Inventory is Empty! "<<endl;
		return;
	}
	if(head->brandName == brandName){
		MobileStore* temp = head;
		head = head->next;
		delete temp;
		cout<<" Mobile Deleted Successfully. "<<endl;
		return;
	}
	MobileStore* temp = head;
	while(temp->next != NULL && temp->next->brandName != brandName){
		temp = temp->next;
	}
	MobileStore* del= temp->next;
	temp->next = del->next;
	delete del;
	cout<<" Mobile Deleted Successfully."<<endl;
}

void displayMobiles(){
	MobileStore* temp = head;
	if (temp == NULL){
		cout<<" No Mobile Phone present in the Inventory. "<<endl;
		return;
	}
	cout<<" \n Displaying Mobile Phones of Store: "<<endl;
	while (temp!= NULL){
		cout<<" Brand: "<<temp->brandName<<endl;
		cout<<" Units: "<<temp->units<<endl;
		cout<<" Price: Rs "<<temp->price <<" \n "<<endl;
		temp = temp->next;
	}
}
int main(){
	addMobile("Samsung", 5 , 50000);
	addMobile("Apple", 10 , 120000);
	addMobile("Oppo", 8 , 30000);
	
	cout<<"\n Inventory: "<<endl;
	displayMobiles();
	
	deleteMobile("Oppo");
    cout<<"\n After deletion: "<<endl;
    displayMobiles();
    return 0;
}