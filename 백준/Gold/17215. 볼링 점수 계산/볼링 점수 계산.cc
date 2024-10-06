#include <iostream>
#include <string>

using namespace std;

int cal_score(string str){
    int score =0;
    
    int bonus[100]={};
    int round_ =0;
    for(int i=0;i<str.length();i++){
        round_++;
        if(str[i] == 'S'){
            score += 10;
            if(bonus[i] > 0) score += 10*bonus[i];
            if(round_ < 10) {bonus[i+1]++; bonus[i+2]++;}
        }
        else{
            int before =0;
            if(str[i] != '-'){
                score += str[i] -'0';
                if(bonus[i] > 0) score += (str[i] -'0')*bonus[i];
                before = str[i] -'0';
            }
            i++;
            if(i==str.length()) break;
            if(str[i] == 'P'){
                score += 10-before;
                if(bonus[i] > 0) score += (10-before)*bonus[i];
                if(round_ < 10) bonus[i+1]++;
            }
            else {
                if(str[i] != '-'){
                    score += str[i] -'0';
                    if(bonus[i] > 0) score += (str[i] -'0')*bonus[i];
                }
            }
        }
        // cout << " round : " << round_ << " " << score << '\n';
    }
    
    return score;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    string str;
    cin >> str;
    
    cout << cal_score(str);
    
    return 0;
}