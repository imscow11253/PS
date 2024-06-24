#include <iostream>
#include <map>

using namespace std;

long p,q;
map<long,long> mp;

long count(long n){
    if(n==0) return 1;
    else if(mp.find(n) != mp.end()) return mp[n];
    else{
        mp[n] = count(n/p) + count(n/q);
        return mp[n];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long n;
    cin >> n >> p >> q;
    
    if(n ==0) cout << 1;
    else {
        count(n);
        cout << mp[n];
    }
    
    return 0;
}