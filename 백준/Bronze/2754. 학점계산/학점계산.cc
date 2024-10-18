#include <iostream>
#include <string>

using namespace std;

string arr[13] = {"A+", "A0", "A-","B+","B0","B-","C+","C0","C-","D+","D0","D-","F"};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    
    int index;
    for(int i=0;i<13;i++){
        if(arr[i] == str){
            index= i;
        }
    }
    
    switch(index){
        case 0:
            cout << 4.3;
            break;
        case 1:
            cout << "4.0";
            break;
        case 2:
            cout << 3.7;
            break;
        case 3:
            cout << 3.3;
            break;
        case 4:
            cout << "3.0";
            break;
        case 5:
            cout << 2.7;
            break;
        case 6:
            cout << 2.3;
            break;
        case 7:
            cout << "2.0";
            break;
        case 8:
            cout << 1.7;
            break;
        case 9:
            cout << 1.3;
            break;
        case 10:
            cout << "1.0";
            break;
        case 11:
            cout << 0.7;
            break;
        case 12:
            cout << "0.0";
            break;
            
    }
    
    return 0;
}