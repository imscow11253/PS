#include <iostream>

using namespace std;

int n;
int arr[200000];
int hol=0;
int jjak=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]%2==1) hol++;
        else jjak++;
    }
    
    if(hol==0 && jjak ==1) {cout <<0; return 0;}
    if(hol==0 && jjak ==0) {cout << 1;return 0;}
    if(jjak==0 && hol%2==0) {cout << 0;return 0;}
    if(jjak==0 && hol%2==1) {cout << 1;return 0;}
    if(hol%2==0){
        int set_num=0;
        int jjak_set=0;
        for(int i =0;i<n;i++){
            if(arr[i]%2==0) {jjak_set++;}
            else{
                while(i+1<n && arr[i+1]%2==0){
                    i++;
                }
                i++;
                set_num++;
            }
        }
        if((set_num+jjak_set)==1) cout << 0;
        else cout << 1;
    }
    else{
        cout << 1;
    }

    
    return 0;
}