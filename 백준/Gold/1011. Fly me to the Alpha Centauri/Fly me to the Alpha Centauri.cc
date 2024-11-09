#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int sta, end;
        cin >> sta >> end;
        
        int value = end - sta;
        int root = sqrt(value);
        if(pow(root,2) == value){
            cout << root*2-1 <<'\n';
        }
        else{
            if(pow(root,2)+root >= value){
                cout << root*2 <<'\n';
            }
            else{
                cout << root*2+1 <<'\n';
            }
        }
    }
    
    return 0;
}