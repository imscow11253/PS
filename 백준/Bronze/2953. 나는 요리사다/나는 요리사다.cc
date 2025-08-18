#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int max_index;
    int max_value =0;
    int a,b,c,d;
    for(int i =1;i<=5;i++){
        cin >> a >> b >> c >> d;
        if(a+b+c+d > max_value){
            max_value = a+b+c+d;
            max_index = i;
        }
    }
    
    cout << max_index << " " << max_value;
    
    return 0;
}