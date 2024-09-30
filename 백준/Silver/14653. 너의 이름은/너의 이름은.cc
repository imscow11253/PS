#include <iostream>

using namespace std;

int n, k,q;
pair<int,char> arr[10000];
bool people[26] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k >>q;
    
    int a; char b;
    for(int i =0;i<k;i++){
        cin >> a >> b;
        arr[i] = {a,b};
    }
  
    for(int i=0;i<q-1;i++){
        if(arr[i].first == arr[q-1].first){
            people[arr[i].second-'A'] = true;
        }
    }
    for(int i=q-1;i<k;i++){
        people[arr[i].second-'A'] = true;
    }
    people[0] = true;
    
    int check=0;
    if(arr[q-1].first ==0){
        cout << -1 << '\n';
    }
    else{
        for(int i =0;i<n;i++) {
            if(!people[i]) {
                cout << (char)(i+'A') << " ";
                check=1;
            }
        }
        if(!check) cout << -1;
    }
    
    return 0;
}