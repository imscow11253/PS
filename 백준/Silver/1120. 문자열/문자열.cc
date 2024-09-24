#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a,b;
    cin >> a >> b;
    
    int min=INT_MAX;
    for(int i=0;i<=b.length()-a.length();i++){
        int diff=0;
        for(int j=0;j<a.length();j++){
            if(b[i+j] != a[j]) diff++;
        }
        if(diff < min) {
            min = diff;
        }
    }
    
    cout << min;
    
    return 0;
}