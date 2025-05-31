#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std ; 

// nothing to care about 
void Search() ; 
int homepage(); 

struct User{
    string accnum ; 
    string name ; 
    string lname ; 
    string id ; 
    string phnum ; 
    long long int balance ;
};

void opening_account(User a){
	system("CLS"); 
	
	// geting information  
	cout<<"DniBank - Opening Account"<<endl ; 
	char check='N' ;
	cout<<"Enter account number: " ; 
	cin>> a.accnum ; 
	cout<<"Enter name: " ;
	cin>> a.name ; 
	cout<<"Enter last name: ";
	cin>> a.lname ;
	cout<<"Enter id: ";
	cin>> a.id ; 
	cout<<"Enter phone number: "; 
	cin>> a.phnum ;
	cout<<"Enter first balance: ";
	cin>> a.balance ; 
	
	// import to file  
	fstream BankData ; 
	BankData.open("BankData.txt", ios::app); 
	BankData<< a.accnum <<"*"<< a.name <<"*"<< a.lname<<"*"<< a.id <<"*"<< a.phnum <<"*" << a.balance << endl ;
	BankData.close(); 
	cout<<endl<<"User Information saved !" ; 
	cout<<endl<<"Press any kay to quit..." ; 
    char c='^' ; 
    while(c=='^'){
        cin>> c ; 
    }
}

void sby_id(){
	system("CLS"); 
	char temp[200] , findkey[20] ;
	char *temp1, *K1=NULL, *K2=NULL, *K3=NULL, *K4=NULL, *K5=NULL, *K6=NULL ; 
	cout<<"DniBank - Search by id"<<endl<<"Enter the id you want to search for : " ;
	cin>> findkey ; 
	fstream BankData ; 
	BankData.open("BankData.txt",ios::in);  
	
	bool userfound = false ; 
	while(BankData.getline(temp,200)){
		K1 = K2 = K3 = K4 = K5 = K6 = NULL ; 
		temp1 = strtok(temp,"*");
		if(temp1) K1 = temp1 ; 
		temp1 = strtok(NULL,"*"); 
		if(temp1) K2 = temp1 ; 
		temp1 = strtok(NULL,"*");
		if(temp1) K3 = temp1 ; 
		temp1 = strtok(NULL,"*"); 
		if(temp1) K4 = temp1 ; 
		temp1 = strtok(NULL,"*");
		if(temp1) K5 = temp1 ; 
		temp1 = strtok(NULL,"*");
		if(temp1) K6 = temp1 ; 
		temp1 = strtok(NULL,"*");
		
		if(K4 && strcmp(K4,findkey)==0 ){
			userfound = true ; 
			cout<<endl<<"User found ! Here is the information : "<< endl ; 
			cout<< (K1 ? K1 : "") <<" "<<(K2 ? K2 : "")<<" "<<(K3 ? K3 : "")<<" "<<(K4 ? K4 : "")<<" "<<(K5 ? K5 : "")<<" "<<(K6 ? K6 : "")<< endl ;   
			}
		}
		if(!userfound){
			cout<<endl<<"User not found !"<<endl ; 
		}
		char w='~' ; 
		BankData.close(); 
		cout<<endl<<"Press any key to continue... " ; 
		while(w=='~'){
		cin>> w ; 
		}
}

void sby_accnum(){
	system("CLS"); 
	char temp[200] , findkey[20] ;
	char *temp1, *K1=NULL, *K2=NULL, *K3=NULL, *K4=NULL, *K5=NULL, *K6=NULL ; 
	cout<<"DniBank - Search by id"<<endl<<"Enter the account number you want to search for : " ;
	cin>> findkey ; 
	fstream BankData ; 
	BankData.open("BankData.txt",ios::in);  
	
	bool userfound = false ; 
	while(BankData.getline(temp,200)){
		K1 = K2 = K3 = K4 = K5 = K6 = NULL ; 
		temp1 = strtok(temp,"*");
		if(temp1) K1 = temp1 ; 
		temp1 = strtok(NULL,"*"); 
		if(temp1) K2 = temp1 ; 
		temp1 = strtok(NULL,"*");
		if(temp1) K3 = temp1 ; 
		temp1 = strtok(NULL,"*"); 
		if(temp1) K4 = temp1 ; 
		temp1 = strtok(NULL,"*");
		if(temp1) K5 = temp1 ; 
		temp1 = strtok(NULL,"*");
		if(temp1) K6 = temp1 ; 
		temp1 = strtok(NULL,"*");
		
		if(K1 && strcmp(K1,findkey)==0 ){
			userfound = true ; 
			cout<<endl<<"User found ! Here is the information : "<< endl ; 
			cout<< (K1 ? K1 : "") <<" "<<(K2 ? K2 : "")<<" "<<(K3 ? K3 : "")<<" "<<(K4 ? K4 : "")<<" "<<(K5 ? K5 : "")<<" "<<(K6 ? K6 : "")<< endl ;   
			}
		}
		if(!userfound){
			cout<<endl<<"User not found !"<<endl ; 
		}
		char w='~' ; 
		BankData.close(); 
		cout<<endl<<"Press any key to continue... " ; 
		while(w=='~'){
		cin>> w ; 
		}
}

void show_all(){
	system("CLS");
	cout<<"DniBank - Show All" << endl ;
	cout<<"Account number  -  Name  -  Last Name  -  ID  -  Phone number  -  Balance"<< endl ;  
	fstream BankData ; 
	BankData.open("BankData.txt",ios::in); 
	char temp[200] ; 
	while(!BankData.eof()){
		BankData.getline(temp,200); 
		cout<< temp << endl ; 
	}
	BankData.close() ; 
	char w='~' ; 
	cout<<endl<<"Press any key to continue... " ; 
		while(w=='~'){
		cin>> w ; 
		}
}

void Search(){
	system("CLS");
	char a ; 
	cout<<"DniBank - Search "<<endl<<"[I] search by id "<<endl<<"[A] search by account number "<<endl<<"[S] show all"<<endl<<"[E] exit "<< endl ;
	cout<<endl<<"Choose an option... " ; 
	cin>> a ; 
	while(a!='E' && a!='e'){
		switch(a){
			case 'i': 
			case 'I': sby_id(); break;
			case 'a': 
			case 'A': sby_accnum(); break;
			case 's':
			case 'S': show_all(); break; 
			case 'E':
			case 'e': homepage(); break ; 
		}
	} 
}

void dby_id(){
	system("CLS"); 
	char temp[200] , findkey[20] ;
	char *temp1, *K1=NULL, *K2=NULL, *K3=NULL, *K4=NULL, *K5=NULL, *K6=NULL ; 
	cout<<"DniBank - Search by id"<<endl<<"Enter the account number you want to delete : " ;
	cin>> findkey ; 
	fstream BankData ; 
	BankData.open("BankData.txt",ios::in);  
			
	fstream helpfile ; 
	helpfile.open("helpfile.txt",ios::app);  
	
	bool userfound = false ; 
	while(BankData.getline(temp,200)){
		K1 = K2 = K3 = K4 = K5 = K6 = NULL ; 
		temp1 = strtok(temp,"*");
		if(temp1) K1 = temp1 ; 
		temp1 = strtok(NULL,"*"); 
		if(temp1) K2 = temp1 ; 
		temp1 = strtok(NULL,"*");
		if(temp1) K3 = temp1 ; 
		temp1 = strtok(NULL,"*"); 
		if(temp1) K4 = temp1 ; 
		temp1 = strtok(NULL,"*");
		if(temp1) K5 = temp1 ; 
		temp1 = strtok(NULL,"*");
		if(temp1) K6 = temp1 ; 
		temp1 = strtok(NULL,"*");

		if(K4 && strcmp(K4,findkey)==0 ){
			userfound = true ; 
			cout<<endl<<"User found ! deletion is in progress ."<< endl ; 
			}else{
				helpfile << (K1 ? K1 : "") <<"*"<<(K2 ? K2 : "")<<"*"<<(K3 ? K3 : "")<<"*"<<(K4 ? K4 : "")<<"*"<<(K5 ? K5 : "")<<"*"<<(K6 ? K6 : "")<< endl ;  
			}
		}
		
		helpfile.close();
    	BankData.close();

		if(!userfound){
			cout<<endl<<"User not found !"<<endl ; 
		}else{
			remove("BankData.txt"); 
			rename("helpfile.txt","BankData.txt"); 
		}
		
		char w='~' ; 
		cout<<endl<<"Press any key to continue... " ; 
		while(w=='~'){
		cin>> w ; 
		}
			
	homepage() ;  
}

dby_accnum(){
	
}

void del(){
	system("CLS");
	char a ; 
	cout<<"DniBank - Search "<<endl<<"[I] delete by id "<<endl<<"[A] delete by account number "<<endl<<"[E] exit "<< endl ;
	cout<<endl<<"Choose an option... " ; 
	cin>> a ; 
	while(a!='E' && a!='e'){
		switch(a){
			case 'i': 
			case 'I': dby_id(); break;
			case 'a': 
			case 'A': dby_accnum(); break;
			case 'E':
			case 'e': homepage(); break; 
		}
	} 	
}

void pay(){
	
}

void transfer(){
	
}

int homepage(){
	system("CLS");
	User user ; 
    char a ;
    cout<<"DniBank - Home Page"<<endl<<"[O] opening account"<<endl<<"[S] search"<<endl<<"[D] delete"<< endl<< "[P] pay"<<endl<<"[T] transfer"<< endl <<"[E] exit"<< endl; 
	cout<<endl<<"Choose an option... " ;
    cin>>a ; 
    while(a!='e' && a!='E'){
    	switch (a){
    		case 'O': 
			case 'o': opening_account(user); break;  
			case 's': 
			case 'S': Search(); break ; 
			case 'D': 
			case 'd': del(); break; 
			case 'P': 
			case 'p': pay(); break;
			case 'T': 
			case 't': transfer(); break; 
			case 'E': 
			case 'e': exit(0) ; 
		}
	}
}

int main(){
    homepage(); 
    return 0 ; 
}
