#include <iostream>

using namespace std;

int n,k;
int meal[6];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    for(int i =0;i<6;i++){
        cin >> meal[i];
    }
    
    int cri = meal[1];
    for(int i =0;i<n;i++){
        //아침 to 점심
        if(cri+k >= meal[3]) cri = meal[3];
        else if(cri+k < meal[2]) {cout << "NO"; return 0;}
        else cri = cri+k;
        // cout << cri << '\n';
        //점심 to 저녁
        if(cri+k >= meal[5]) cri = meal[5];
        else if(cri+k < meal[4]) {cout << "NO"; return 0;}
        else cri = cri+k;
        // cout << cri << '\n';
        //저녁 to 아침
        if(i != n-1){
            if(cri+k >= meal[1]+1440) cri = meal[1];
            else if(cri+k < meal[0]+1440) {cout << "NO"; return 0;}
            else cri = cri+k-1440;
            // cout << cri << '\n';
        }
    }
    
    cout << "YES";
    
    return 0;
}