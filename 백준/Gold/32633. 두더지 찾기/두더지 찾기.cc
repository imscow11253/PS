#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[100001] ={};
int b[100001] ={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long l;
    cin >>  n >> l;
    
    for(int i =1;i<=n;i++){
        cin >> a[i];
    }
    for(int i =1;i<=n;i++){
        cin >> b[i];
    }
    
    long long res=1;
    for(int i=1;i<=n;i++){
        if(!b[i]) continue;
        res = lcm(a[i], res);
        if(res > l) {cout << -1; return 0;}
    }
    
    for (int i=1;i<=n;i++) {
		if (b[i]) continue;
		if (res % a[i] == 0) {cout << -1; return 0;}
	}
	
	cout << res;
    
    return 0;
}