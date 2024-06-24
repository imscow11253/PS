#include <iostream>

using namespace std;

void hanoi(int n, int sta, int via ,int end){
    if(n==1) cout << sta << " " << end << '\n'; 
    else{
        hanoi(n-1, sta, end, via);
        cout << sta << " " << end << '\n';
        hanoi(n-1, via, sta, end);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int arr[21];
    arr[1] = 1;
    for(int i =2;i<=n;i++){
        arr[i] = arr[i-1] * 2 +1;
    }
    cout << arr[n]<< '\n';
    
    hanoi(n,1,2,3);
    
    return 0;
}