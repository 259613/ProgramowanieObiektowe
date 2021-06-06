///@file

#include <iostream>
#include "utility.hpp"

using namespace std;
int wprowadzInt(){
	int x;
	cin >> x;
	while (!cin){
	  czyscBufor();
		cin >> x;	
	}
	return x;
}

int wprowadzZakres(int min, int max){
    while(true){
		cout << "\n Zakres ( " << min << " - " << max << " ): "; 
        int x = wprowadzInt();
        
        if(x>max){
            cout << "Wprowadzona liczba jest za wysoka! ";
        }
        else if( x < min ){
            cout << "Wprowadzona liczba jest za niska! ";
        }
        else{
            return x;
        }
    }
}

void czyscBufor(){
    cin.clear();
    cin.ignore(1000,'\n');
}
