#include <iostream>
#include <set>

using namespace std;

int n;
set<int> sosu;
bool arr[10001] = {};

void get_sosu(){
    for(int i=2;i<=10000;i++){
        if(arr[i] == false){
            sosu.insert(i);
            int index =i;
            while(index <= 10000){
                arr[index] = true;
                index +=i;
            }
        }
    }
}

void gold(int num){
    int l = num/2;
    int r = num/2;
    while(sosu.find(l) == sosu.end() || sosu.find(r) == sosu.end()){
        l--;
        r++;
    }
    cout << l << " " << r << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    get_sosu();
    // for(int a : sosu) cout << a << " ";
    // cout << '\n';
    
    int temp;
    while(n--){
        cin >> temp;
        gold(temp);
    }
    
    return 0;
}