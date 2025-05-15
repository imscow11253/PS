#include <iostream>
#include <set>
#include <string>

using namespace std;

int n,k;
int card[10];
set<string> st;
bool visit[10]={0,};

void select_card(int num, string result){
    if(num == k){
        st.insert(result);
        return ;
    }
    for(int i =0;i<n;i++){
        if(visit[i]) continue;
        visit[i] = true;
        select_card(num+1, result + to_string(card[i]));
        visit[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    for(int i =0;i<n;i++){
        cin >> card[i];
    }
    
    select_card(0,"");
    
    // for(string a : st) cout << a << " "; cout << '\n';
    cout << st.size();
    
    return 0;
}