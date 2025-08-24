#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sum =0;
    int min_value = 101;
    int temp;
    for(int i =0;i<7;i++){
        cin >> temp;
        if(temp%2==1){
            min_value = min(min_value, temp);
            sum += temp;
        }
    }
    
    if(sum ==0){
        cout << -1; return 0;
    }
    
    cout << sum << '\n' << min_value;
    
    return 0;
}