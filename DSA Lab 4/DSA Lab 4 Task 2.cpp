#include <iostream>
using namespace std;
struct Profile{
	string username;
	int age;
	string bio;
	Profile* next;
};

Profile* head = NULL;
void createProfile(string username, int age, string bio){
	Profile* newProfile = new Profile;
	newProfile->username = username;
	newProfile->age = age;
	newProfile->bio = bio;
	newProfile->next = head;
	head = newProfile;
}

void updateProfile(string username, int newAge, string newBio){
	Profile* temp = head;
	while (temp != NULL){
		if(temp->username == username){
			temp->age = newAge;
			temp->bio = newBio;
			cout<<"\n Profile Updated Successfully! "<<endl;
			return;
		}
		temp= temp->next;
	}
	cout<<" Profile not Found! "<<endl;
}

void deleteProfile(string username){
	if(head == NULL){
		cout<<" No Profile Available." <<endl;
		return ;
	}
	if(head->username == username){
		Profile* temp= head;
		head = head->next;
		delete temp;
		cout<<" Profile deleted Successfully."<<endl;
		return;
	}
	Profile* temp= head;
	while(temp->next !=NULL && temp->next->username != username){
		temp = temp->next;
	}
	if(temp->next == NULL){
		cout<<" Profile not Found. "<<endl;
		return ;
	}
	Profile* del = temp->next;
	temp->next = del->next;
	delete del;
	cout<<"\n Profile Deleted Successfully. "<<endl;
}

void searchProfile(string username){
	Profile* temp = head;
	while (temp != NULL){
		if(temp->username == username) {
            cout<<" Found Profile -> Username: " << temp->username<<endl;
            cout<<" Age: " << temp->age<<endl; 
            cout<< " Bio: " << temp->bio << endl;
            return;
        }
        temp = temp->next;
	}
	cout<<" Profile Not Found. "<<endl;
}

void viewProfiles(){
	Profile* temp = head;
	if(temp == NULL){
		cout<<" No Profile Available. "<<endl;
		return;
	}
	while (temp != NULL){
		cout<<"\n Username: "<<temp->username<<endl;
		cout<<" Age: "<<temp->age<<endl;
		cout<<" Bio: "<<temp->bio<<endl;
		temp = temp->next;
	}
}
int main(){
	createProfile("Iqra Nayab" , 20, "Software Engineer");
	createProfile("Ali" , 15, "Footballer");
	createProfile("Sara", 20, "Loves photography");

	cout<<" All Profiles: \n ";
    viewProfiles();
    
    cout<<"\n Searching for Profile: "<<endl;
    searchProfile("Ali");
    
	updateProfile("Sara", 21, "Travel blogger");
    cout << "\nAfter update:\n";
    viewProfiles();

    deleteProfile("Iqra Nayab");
    cout << "\nAfter deletion:\n";
    viewProfiles();

    return 0;
}