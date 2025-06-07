#include <iostream>

using namespace std;

int n;
int card[1000001];
bool check[1000001] = {0,};
long long score[1000001] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> card[i];
        check[card[i]] = true;
    }
    
    for(int i =0;i<n;i++){
        long long player_card = (long long)card[i];
        for(long long j = player_card*2; j < 1000001; j+=player_card){
            if(check[j]) {
                score[j]--;
                score[player_card]++;
            }
        }
    }
    
    for(int i =0;i<n;i++){
        cout << score[card[i]] << " ";
    }
    
    return 0;
}