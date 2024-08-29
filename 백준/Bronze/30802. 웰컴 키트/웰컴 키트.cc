#include <iostream>

using namespace std;

int arr[6];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i =0;i<6;i++){
        cin >> arr[i];
    }
    
    int t,p;
    cin >> t >> p;
    
    int t_cnt=0;
    for(int a : arr){
        if(a ==0) continue;
        int divide = a/t;
        int remain = a%t;
        if(remain !=0) t_cnt += divide+1;
        else t_cnt += divide;
    }
    
    cout << t_cnt << '\n';
    cout << n/p << " " << n%p;
    
    return 0;
}