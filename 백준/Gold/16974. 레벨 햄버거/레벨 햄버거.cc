#include <iostream>

using namespace std;

long long n, x;
int arr[51];
long long _size[51];
long long patty[51];

void travel(long long n, long long x, long long ate){
    //cout << n << " " << x << " " << ate<< '\n';
    if(n==0) {
        if(x <=0){
            cout << ate;
        }
        else{
            cout << ate+1;
        }
        exit(0);
    }
    
    if(_size[n]/2 +1 == x){
        cout << ate+patty[n-1]+1;
        exit(0);
    }
    
    if(_size[n]/2 +1 < x){
        travel(n-1, x-_size[n-1]-1-1, ate+patty[n-1]+1);
    }
    
    if(_size[n]/2 +1 > x){
        travel(n-1, x-1, ate);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> x;
    
    if(x==1) {
        cout << 0;
        exit(0);
    }
    
    _size[0]=1;
    patty[0]=1;
    for(int i=1;i<51;i++){
        _size[i] = _size[i-1] *2 +3;
        patty[i] = patty[i-1]*2 +1;
        //cout << "size = " << _size[i] << " patty = " << patty[i] << '\n';
    }
    
    travel(n,x,0);
    
    return 0;
}