#include <iostream>
#include <string>

using namespace std;

string str1, str2, str3;

void myFun(string index){
    long long i = stoll(index);
    
    if(index == str1) i += 3;
    else if(index == str2) i += 2;
    else if(index == str3) i+= 1;
    
    if(i % 15 == 0) cout << "FizzBuzz";
    else if(i% 3 == 0) cout << "Fizz";
    else if(i% 5 == 0) cout <<"Buzz";
    else cout << i;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str1 >> str2 >> str3;
    
    if(str1[0] >= '0' && str1[0] < 'A'){
        myFun(str1);
    }
    else if(str2[0] >= 48 && str2[0] < 'A'){
        myFun(str2);
    }
    else myFun(str3);
    
    return 0;
}