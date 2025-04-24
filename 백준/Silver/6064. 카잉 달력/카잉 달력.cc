#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    int A = max(a,b);
    int B = min(a,b);
    
    while(A % B != 0){
        int R = A % B;
        A = B;
        B = R;
    }
    return B;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int m,n,x,y;
        cin >> m >> n >> x >> y;
        
        int chesogongbae = m*n/gcd(m,n);
        int i=1;
        int j=1;
        int result=1;
        int check =1;
        while(result <= chesogongbae){
            // cout << i << " " << j << '\n';
            if(i -j == x - y){
                while(i != x || j != y){
                    i++; j++; result++;
                }
                cout << result << '\n';
                // cout << "result : " << result << '\n';
                check =0;
                break;
            }
            if(m-i < n-j){
                j += m-i+1;
                result += m-i+1;
                i = 1;
                continue;
            }
            i += n-j+1;
            result += n-j+1;
            j =1;
        }
        if(check) cout << -1 << '\n';
    }
    
    return 0;
}