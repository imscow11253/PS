#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int dice[6];
int one_side = 100;
int two_side= 200;
int three_side=300;

void get_sides(){
    for(int a : dice){
        one_side = min(one_side, a);
    }
    for(int i =0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if((i==0&&j==5)||(i==1&&j==4)||(i==2&&j==3)){
                continue;
            }
            two_side = min(two_side, dice[i]+dice[j]);
        }
    }
    for(int i =0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
                if(
                    (i==0&&j==5) || (j==0&&k==5) || (i==0&&k==5) ||
                    (i==1&&j==4) || (j==1&&k==4) || (i==1&&k==4) ||
                    (i==2&&j==3) || (j==2&&k==3) || (i==2&&k==3)
                ){
                    continue;
                }
                three_side = min(three_side, dice[i]+dice[j]+dice[k]);
            }
        }
    }
    // cout << one_side << " " << two_side << " " << three_side <<'\n';
}

long long calculate(){
    if(n==1) {
        sort(dice, dice+6);
        int result=0;
        for(int i =0;i<5;i++){
            result+=dice[i];
        }
        return result;
    }
    long long result=0;
    result += (long long)(n-1)*(n-2)*4*one_side;
    result += (long long)(n-2)*(n-2)*one_side;
    result += (long long)(n-1)*4*two_side;
    result += (long long)(n-2)*4*two_side;
    result += (long long)three_side*4;
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0;i<6;i++){
        cin >> dice[i];
    }
    get_sides();
    cout << calculate();
    
    return 0;
}