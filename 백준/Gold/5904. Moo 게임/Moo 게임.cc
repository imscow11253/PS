#include <iostream>

using namespace std;

int n;
int size_arr[27];

void travel(int index, int target){
    if(index==0){
        if(target == 1) cout << "m";
        else cout << "o";
        return;
    } 
    //cout << index << " " << target << '\n';
    if(size_arr[index-1] >= target){
        travel(index-1, target);
    }
    else if(size_arr[index-1] + index + 3 < target){
        travel(index-1, target - size_arr[index-1] - index - 3);
    }
    else{
        if(target == size_arr[index-1]+1 ) cout << "m";
        else cout << "o";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int sum =3;
    int index=0;
    while(sum <= n){
        //cout << index++ << " : " << sum << "\n";
        size_arr[index++] = sum;
        sum = sum*2 + index+3;
    }
    
    travel(index,n);
    
    
    
    return 0;
}
