#include <iostream>
#include <string>

using namespace std;

bool result[50] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=0;i<50;i++){
        result[i] = true;
    }
    
    string index;
    cin >> index;
    
    string temp;
    for(int i =1;i<n;i++){
        cin >> temp;
        for(int j=0;j<index.length();j++){
            if(temp[j] != index[j]) result[j] = false;
        }
    }
    
    for(int i =0;i<index.length();i++){
        if(result[i]) cout << index[i];
        else cout << "?";
    }
    
    
    return 0;
}