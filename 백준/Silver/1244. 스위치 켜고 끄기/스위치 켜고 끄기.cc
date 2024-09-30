#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool switches[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++) cin >> switches[i];
    
    int t;
    cin >> t;
    
    int sex, num;
    while(t--){
        cin >> sex >> num;
        int count = num;
        if(sex == 1){
            while(num <= n){
                switches[num] = !switches[num];
                num += count;
            }
        }
        else if(sex == 2){
            int l = num-1;
            int r = num+1;
            switches[num] = !switches[num];
            while(l >0 && r <= n){
                if(switches[l] == switches[r]){
                    switches[l] = !switches[l];
                    switches[r] = !switches[r];
                }
                else {
                    break;
                }
                l--;
                r++;
            }
        }
        // for(int i=1;i<=n;i++) cout << switches[i] << " ";
        // cout << '\n';
    }
    
    for(int i=1;i<=n;i++) {
        cout << switches[i] << " ";
        if(i%20 == 0) cout << '\n';
    }
    
    return 0;
}