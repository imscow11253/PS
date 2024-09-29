#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int t,n;
int location[100001];
int items[100001][54] = {0,};
vector<int> logOfInvalidCommand;
set<int> invalidPlayer;

void check_invalid(int num, int player, char command){
    int object1, object2;
    cin >> object1;
    switch (command){
        case 'M':
            location[player] = object1;
            break;
        case 'F':
            if(location[player] != object1){
                logOfInvalidCommand.push_back(num);
            }
            items[player][object1]++;
            break;
        case 'C':
            cin >> object2;
            if(items[player][object1] >=1 && items[player][object2] >= 1){
                items[player][object1]--;
                items[player][object2]--;
            }
            else{
                logOfInvalidCommand.push_back(num);
                if(items[player][object1] !=0) items[player][object1]--;
                if(items[player][object2] !=0) items[player][object2]--;
            }
            break;
        case 'A':
            if(location[player] != location[object1]){
                logOfInvalidCommand.push_back(num);
                invalidPlayer.insert(player);
            }
            break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t >> n;
    
    for(int i=0;i<=n;i++){
        location[i] =1;
    }
    
    int num, player;
    char command;
    while(t--){
        cin >> num >> player >> command;
        check_invalid(num, player, command);
    }
    
    cout << logOfInvalidCommand.size() << '\n';
    sort(logOfInvalidCommand.begin(), logOfInvalidCommand.end());
    for(int i=0;i<logOfInvalidCommand.size();i++){
        if(i == logOfInvalidCommand.size()-1) cout << logOfInvalidCommand[i] << '\n';
        else cout << logOfInvalidCommand[i] << " ";
    }
    cout << invalidPlayer.size() << '\n';
    for(int a : invalidPlayer) cout << a << " ";
    
    return 0;
}