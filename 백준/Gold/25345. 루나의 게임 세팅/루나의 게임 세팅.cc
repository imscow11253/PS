#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n,k;
vector<int> vec;
int divide = 1000000007;

int check[2000]= {};
int cnt=1;
int memo[2001][2001] = {0,};

void travel(int a){
    // for(int i =0;i<k;i++){
    //     cout << check[i] << " ";
    // }cout << '\n';
    if(a==k-1){
        cnt++;
    }
    for(int i=0;i<k;i++){
        if(check[i] && i-1 >=0 && !check[i-1]){
            check[i-1]=1;
            travel(a+1);
            check[i-1]=0;
        }
        if(check[i] && i+1 <k && !check[i+1]){
            check[i+1]=1;
            travel(a+1);
            check[i+1]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    
    int temp; 
    int num=n;
    while(n--){
        cin >> temp;
        vec.push_back(temp);
    }
    
    // long long sum=1;
    // for(int i=0;i<k;i++){
    //     sum *= num--;
    //     sum /= i+1;
    //     sum %= divide;
    //     // cout << sum << '\n';
    // }

    for(int i=0; i<=num; i++) {
		memo[i][0] = 1;
		for(int j=1; j<=i; j++) {
			memo[i][j] = (memo[i-1][j-1] + memo[i-1][j]) % divide;
		}
	}
	int sum = memo[num][k];
    // for(int i =0;i<k;i++){
    //     check[i]=1;
    //     travel(0);
    //     check[i]=0;
    // }
    for(int i =0;i<k-1;i++){
        sum *= 2;
        sum %= divide;
    }
    // cout << cnt << " " << sum << '\n';
    cout << sum;
    
    return 0;
}