#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i =0;i<n;i++) cin >> vec[i];
        
    vector<bool> visit(n, true);
    int index =0;
    int result=0;
    while(result < n){
        cout << index+1 << " ";
        visit[index] = false;
        result++;
        if(result == n) break;
        int value = abs(vec[index]);
        int direction = (vec[index] < 0) ? -1 : 1;
        for(int i =0;i<value; ){
            index += direction;
            if(index < 0) index = n-1;
            if(index == n) index =0;
            if(visit[index]) {
                i++;
            }
        }
    }
    
    return 0;
}