#include <iostream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,n;
    cin >> m >>n;
    
    set<int> values;
    for(int i=1;i<=10000;i++){
        values.insert(i*i);
    }
    
    int sum=0;
    int result=0;
    for(int i =m;i<=n;i++){
        if(values.find(i) != values.end()){
            sum+= i;
            if(result ==0) result = i;
        }
    }
    
    if(sum ==0) cout << -1;
    else{
        cout << sum << '\n' << result;
    }
    
    return 0;
}