#include <iostream>
#include <string>

using namespace std;

int n;

bool is_slumps(string str){
    bool result = false;
    for(int i=0;i<str.length();i++){
        if(i==0 && (str[i] == 'D' || str[i] == 'E')){
            i++;
            while(str[i] == 'F'){
                i++;
            }
            if(str[i] == 'D' || str[i] == 'E') {/*cout << str.substr(i, str.length()-i-1) << '\n'; */result = is_slumps(str.substr(i, str.length()-i));}
            else if(i == str.length()-1 && str[i] == 'G') result = true;
        }
    }
    return result;
}

bool is_slimp(string str){
    bool result = false;
    
    if(str.length() == 2 && str == "AH"){
        return true;
    }
    
    for(int i=0;i<str.length();i++){
        if(i ==0 && str[i] == 'A'){
            if(str[i+1] == 'B' && str[str.length()-1] == 'C'){
                if(is_slimp(str.substr(2, str.length()-3))){
                    result = true;
                }
            }
            else if(is_slumps(str.substr(1, str.length()-2)) && str[str.length()-1] == 'C'){
                result = true;
            }
        }
    }
    return result;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    string str;
    cout << "SLURPYS OUTPUT\n";
    while(n--){
        cin >> str;
        if(str.length() ==1 ) {cout << "NO\n"; continue;}
        int check=0;
        for(int i=2;i<str.length();i++){
            // cout << str.substr(0,i) << " " << str.substr(i,str.length()-i) << '\n';
            // cout << is_slimp(str.substr(0,i)) << " " << is_slumps(str.substr(i,str.length()-i)) << '\n';
            if(is_slimp(str.substr(0,i)) && is_slumps(str.substr(i,str.length()-i))){
                check=1;
            }
        }
        if(check){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    cout << "END OF OUTPUT\n";
    
    return 0;
}