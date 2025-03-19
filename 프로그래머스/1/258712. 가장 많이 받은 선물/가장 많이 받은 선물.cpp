#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int transitions[50][50] = {0,};
int giftJisoo[50] = {0,};
map<string, int> friendsIndex;
int result[50] = {0,};

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(int i=0;i<friends.size();i++){
        friendsIndex.insert({friends[i], i});
    }
    
    //update
    for(string transition : gifts){
        string from = transition.substr(0, transition.find(" ",0));
        string to = transition.substr(transition.find(" ",0)+1);
        
        int fromIndex = friendsIndex.find(from) -> second;
        int toIndex = friendsIndex.find(to) -> second;
        
        // cout << fromIndex << " " << toIndex << '\n';
        
        //transitions update
        transitions[fromIndex][toIndex]++;
        
        //giftJisoo udpate
        giftJisoo[fromIndex]++;
        giftJisoo[toIndex]--;
    }
    
    // for(int i =0;i<friends.size();i++){
    //     for(int j=0;j<friends.size();j++){
    //         cout << transitions[i][j] << " ";       
    //     }cout << '\n';
    // }
    
    // for(int i =0;i<friends.size();i++){
    //     cout << giftJisoo[i] << " ";
    // }cout << '\n';
    
    for(int i =0;i<friends.size();i++){
        for(int j=i;j<friends.size();j++){
            if(i==j) continue;
            
            if(transitions[i][j] == transitions[j][i]){
                if(giftJisoo[i] > giftJisoo[j]) result[i]++;
                else if(giftJisoo[i] < giftJisoo[j]) result[j]++;
            }
            
            if(transitions[i][j] > transitions[j][i]) result[i]++;
            else if(transitions[i][j] < transitions[j][i]) result[j]++;
        }
    }
    
    for(int i =0;i<friends.size();i++){
        answer = max(answer, result[i]);
    }
    
    return answer;
}