#include <iostream>
#include <string>

using namespace std;

int checkdz(string str){
    int temp = str.find("z="); int num=0; int length;
    bool check = temp >= 0 && temp < str.length();
    while(check){
        if(str[temp-1] != 'd') num++;
        length = str.length();
        str ="";
        for(int i = temp+2; i<length;i++){
            str.push_back(str[i]);
        }
        temp = str.find("z=");
        check = temp >= 0 && temp < length;
    }
    return num;
}

int checkSubstring(string str, string substr, int& length){
    int temp = str.find(substr); int num=0; int length2;
    bool check = temp >= 0 && temp < length;
    while(check){
        length2 = str.length();
        str =""; num += substr.length()-1;
        for(int i = temp+substr.length(); i<length2;i++){
            str.push_back(str[i]);
        }
        temp = str.find(substr);
        check = temp >= 0 && temp < length2;
    }
    return num;
}

int main(){
    
    string str;
    cin >> str;
    
    string arr[7] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s="};
    int length = str.length();
    int num=0;
    
    for(string a : arr){
        num += checkSubstring(str, a, length);
    }
    
    num += checkdz(str);
    
    cout << length -num;
    
    return 0;
}