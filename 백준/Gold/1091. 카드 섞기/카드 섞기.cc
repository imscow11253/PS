#include <iostream>
#include <cmath>

using namespace std;

int n;
int s[48] ={};
int p[48] ={};
int arr[48] = {};
int cnt=0;

int check(){
    // for(int i =0;i<n;i++){
    //     cout << i%3 << " " << p[arr[i]] << ", ";
    // }cout << '\n';
    for(int i =0;i<n;i++){
        if(i%3 != p[arr[i]]) return 0;
    }
    return 1;
}

void travel(){
    int temp[48]={};
    for(int i =0;i<n;i++){
        temp[s[i]] = arr[i];
    }
    for(int i =0;i<n;i++){
        arr[i] = temp[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> p[i];
    }
    for(int i =0;i<n;i++){
        cin >> s[i];
        arr[i] = i;
    }

    for(int i=0;i<1000000;i++){
        if(check()){
            cout << cnt;
            exit(0);
        }
        
        travel();
        cnt++;
    }
    
    cout << -1;
    
    return 0;
}