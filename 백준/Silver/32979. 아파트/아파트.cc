#include <iostream>
#include <queue>

using namespace std;

int n,t;
queue<int> qu;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> t;
    
    int temp;
    for(int i=1;i<=2*n;i++){
        cin >> temp;
        qu.push(temp);
    }
    
    int floo; int index=0;
    int tt = t;
    while(t--){
        // cout << "================\n";
        cin >> floo;
        floo--;
        while(floo--){
            temp = qu.front();
            // cout << "temp : " << temp << '\n';
            qu.pop();
            qu.push(temp);
        }
        cout << qu.front() << " ";
    }
    
    return 0;
}