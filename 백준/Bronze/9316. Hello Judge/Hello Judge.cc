#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cout << "Hello World, Judge ";
        cout << i << "!\n";
    }
    
    return 0;
}