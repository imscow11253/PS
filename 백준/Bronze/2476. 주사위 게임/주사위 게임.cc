#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int result =0;
    while(n--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == b && b == c){
            result = max(result, a*1000 + 10000);
        }
        else if(a== b) result = max(result, a*100 + 1000);
        else if(b ==c) result = max(result, b*100 + 1000);
        else if(a ==c) result = max(result, a*100 + 1000);
        else{
            result = max(result, max(max(a,b),c)*100);
        }
    }
    
    cout << result;
    
    return 0;
}