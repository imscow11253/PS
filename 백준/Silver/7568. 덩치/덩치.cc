#include <iostream>

using namespace std;

int n;
pair<int,int> arr[50];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int a,b;
    for(int i =0;i<n;i++){
        cin >> a >> b;
        arr[i] = {a,b};
    }
    
    int temp;
    int result[50];
    for(int i=0;i<n;i++){
        temp=0;
        auto p = arr[i];
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(p.first < arr[j].first && p.second < arr[j].second) temp++;
        }
        result[i] = temp+1;
    }
    
    for(int i =0;i<n;i++) cout << result[i] << " ";
    
    return 0;
}