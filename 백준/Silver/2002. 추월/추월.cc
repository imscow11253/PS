#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> in(n), out(n);
    unordered_map<string,int> pos;

    for(int i=0;i<n;i++){
        cin >> in[i];
        pos[in[i]] = i;
    }

    for(int i=0;i<n;i++){
        cin >> out[i];
    }

    vector<bool> passed(n,false);

    int result = 0;

    for(int i=0;i<n;i++){
        int cur = pos[out[i]];

        for(int j=0;j<cur;j++){
            if(!passed[j]){
                result++;
                break;
            }
        }

        passed[cur] = true;
    }

    cout << result;
}