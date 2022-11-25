#include <bits/stdc++.h>
#include "headers/color.h"

using namespace std;

void clear(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void getBin(unsigned long long a){
    vector<int> list;

    for (int i = 0; i >-1; i++){
        list.push_back(a%2);
        a = floor(a/2);

		if (a <1){
			break;
		}
    }

	reverse(list.begin(), list.end()); //Reverse vector
	
	cout << endl << GREEN << "Binary: ";
	
    for (auto var : list){
        cout << var;
    }
	cout << NORM;
	list.clear();
}

int main(){
    unsigned long long a;
    string b;

    #ifdef _WIN32
    WinEnableColor();
    #endif

    for(;;){
        cout << CYAN << "Note: Max number is 18,400,000,000,000,000,000." << endl<< NORM;
        cout << "To exit, press ";

        #ifdef _WIN32
        cout <<"\"Ctrl+C\"" << endl << endl;
        #elif __linux__
        cout << "\"Ctrl+Z\"" << endl << endl;
        #elif __unix__
        cout << "\"Ctrl+Q\"" << endl << endl;
        #endif

        cout << "Enter an interger to get the binary value: ";

        if (!(cin >> a)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            clear();
            continue;

            /*Input check whether the input is an interger or not.
            If not it will ignore and reset the screen*/
        }
        else{
            getBin(a);

            cout << "\n";
        }

        cout << "Enter anything to clear: ";
        cin >> b;

        clear();

    }
    return 0;
}