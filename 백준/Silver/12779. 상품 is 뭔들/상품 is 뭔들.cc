#include<bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b){
    return b ? GCD(b,a%b) : a;
}
int main(){
    long long a, b, cnt=0;
    cin >> a >> b;
    for(long long i=1; ; i++){
        long long i2 = i*i;
        if(i2 > b) break;
        if(i2 > a) cnt++;
    }
    long long G = GCD(cnt, b-a);
    if(cnt ==0) cout << 0;
    else cout << cnt/G << '/' << (b-a)/G;
}