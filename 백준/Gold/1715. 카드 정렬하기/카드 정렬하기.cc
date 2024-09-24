#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int temp;
    while(n--){
        cin >> temp;
        pq.push(temp);
    }
    
    ll result=0;
    while(pq.size()!=1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        result += a+b;
        pq.push(a+b);
    }
    
    cout << result;
    
    return 0;
}