#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string str1, str2;
int k;
int dp[2001][2001] = {0,};

int check_min(int a, int b, int c){
    if(a<b){
        if(a<c) return a;
        else return c;
    }else{
        if(b<c) return b;
        else return c;
    }
}

void draw(){
    cout << "=============================\n";
    for(int i =0;i<=str2.length();i++){
        for(int j=0;j<=str1.length();j++){
            cout << dp[i][j] << " ";
        }cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str1 >> str2 >> k;

    for(int i =1;i<=str1.length();i++){
        dp[0][i] = k*i;
    }
    for(int i =1;i<=str2.length();i++){
        dp[i][0] = k*i;
    }
    
    for(int i =1;i<=str2.length();i++){
        for(int j=1;j<=str1.length();j++){
            dp[i][j] = check_min(dp[i][j-1]+k, dp[i-1][j]+k, dp[i-1][j-1] + abs(str1[j-1] - str2[i-1]));
            // draw();
        }
    }
    
    cout << dp[str2.length()][str1.length()];
    
    return 0;
}