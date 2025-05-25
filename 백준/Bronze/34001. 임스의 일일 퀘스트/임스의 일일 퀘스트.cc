#include <iostream>
#include <map>

using namespace std;

int level;
map<int, pair<int,int>> mp;
map<int, pair<int,int>> mp2;

void initial(){
    mp.insert({200, {210, 220}});
    mp.insert({210, {220, 225}});
    mp.insert({220, {225, 230}});
    mp.insert({225, {230, 235}});
    mp.insert({230, {235, 245}});
    mp.insert({235, {245, 250}});
    
    mp2.insert({260, {265, 270}});
    mp2.insert({265, {270, 275}});
    mp2.insert({270, {275, 280}});
    mp2.insert({275, {280, 285}});
    mp2.insert({280, {285, 290}});
    mp2.insert({285, {290, 295}});
    mp2.insert({290, {295, 300}});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> level;
    initial();
    
    for(auto a : mp){
        int bound = a.first;
        int first_degree = a.second.first;
        int second_degree = a.second.second;
        
        int num = 500;
        if(level < bound) cout << 0 << " ";
        else if(level < first_degree) cout << num << " ";
        else if(level < second_degree) cout << num - 200 << " ";
        else cout << num - 400 << " ";
    }
    cout << '\n';
    for(auto a : mp2){
        int bound = a.first;
        int first_degree = a.second.first;
        int second_degree = a.second.second;
        
        int num = 500;
        if(level < bound) cout << 0 << " ";
        else if(level < first_degree) cout << num << " ";
        else if(level < second_degree) cout << num - 200 << " ";
        else cout << num - 400 << " ";
    }
    
    return 0;
}

