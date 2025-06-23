#include <iostream>

using namespace std;

int n;
pair<int,int> arr[6];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int a,b;
    for(int i =0;i<6;i++){
        cin >> a >> b;
        arr[i] = {a,b};
    }
    
    int l=1,s=0;
    for(int i =0;i<3;i++){
        if(arr[i].first == arr[i+2].first && arr[i+1].first == arr[i+3].first){
            a = arr[i+1].first; 
            b = arr[i+2].first;
            s = arr[i+1].second * arr[i+2].second;
            break;
        }
    }
    
    if(s==0 && arr[4].first == arr[0].first && arr[3].first == arr[5].first) {
        s = arr[5].second * arr[4].second;
        a  =arr[4].first;
        b = arr[5].first;
    }
    if(s==0 && arr[4].first == arr[0].first && arr[5].first == arr[1].first) {
        s = arr[5].second * arr[0].second;
        a = arr[5].first;
        b = arr[0].first;
    }
    if(s==0 && arr[5].first == arr[1].first && arr[0].first == arr[2].first) {
        s = arr[0].second * arr[1].second;
        a = arr[1].first;
        b = arr[0].first;
    }
    
    for(int i =0;i<6;i++){
        if(arr[i].first != a && arr[i].first != b) l *= arr[i].second;
    }
    cout << (l - s) * n;
    
    return 0;
}