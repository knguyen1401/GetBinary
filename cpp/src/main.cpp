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

void reset_cin(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    clear();
}

void getDec(unsigned long long a){
    int len = floor(log10(a)) + 1; //Number lenght
    vector<int> list; //For storing digits
    int result = 0;

    for (int i = 0; i < len; i++){
        if (a%10==1 || a%10 ==0){
            list.push_back(a%10);
        }
        else{
            cout<<RED<<"Binary cannot contain " << a%10 << NORM << endl;
            return;
        }
        a/=10;
    }
    reverse(list.begin(), list.end());
    for (int x : list){
        result = result + x*(pow(2, len-1));
        len--;
    }
    /*
    For example, we have 1000101 as a binary code, and we want to convert it to decimal,
    we will do this

    2^6*1
    2^5*0
    2^4*0
    2^3*0
    2^2*1
    2^1*0
    2^0*1

    and the result is the sum of the numbers above.
    */
    cout << GREEN << "Result: " <<result<< NORM <<endl;
    list.clear();
}

void getBin(unsigned long long a){
    vector<int> list;

    for (int i = 0; i >-1; i++){
        list.push_back(a%2);
        a = a/2;

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
    int choice;

    #ifdef _WIN32
    WinEnableColor();
    #endif

    for(;;){
        cout << CYAN << "Note: Max number is 18,446,744,073,709,551,615." << endl<< NORM;
        cout << "To exit, press ";

        #ifdef _WIN32
        cout <<"\"Ctrl+C\"" << endl << endl;
        #elif __linux__
        cout << "\"Ctrl+Z\"" << endl << endl;
        #elif __unix__
        cout << "\"Ctrl+Q\"" << endl << endl;
        #endif

        cout << "Select one option:" << endl << "1. Decimal -> Binary" << endl << "2. Binary -> Decimal" << endl;
        cout<<"Selection: ";
        if(!(cin >> choice) || choice >=3){
            reset_cin();
            continue;
        }
        else{
            if (choice == 1){
                cout << "Enter an integer to get the binary value: ";

                if (!(cin >> a)){
                    reset_cin();
                    continue;

                    /*Input check whether the input is an integer or not.
                    If not it will ignore and reset the screen*/
                }
                else{
                    getBin(a);

                    cout << "\n";
                }
            }
            else if (choice ==2){
                cout << "Enter binary to get integer: ";

                if (!(cin >> a)){
                    reset_cin();
                    continue;

                    /*Input check whether the input is an integer or not.
                    If not it will ignore and reset the screen*/
                }
                else{
                    getDec(a);

                    cout << "\n";
                }
            }
        }

        cout << "Enter anything to clear: ";
        cin >> b;

        clear();

    }
    return 0;
}
