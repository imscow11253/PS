#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>

using namespace std;

string arr[9];

set<int> row_set[9];
set<int> col_set[9];
set<int> can_set[9];

map<pair<int,int>, int> mp;
vector<pair<int,int>> zero;
vector<int> result;

void initial(){
    for(int i =0;i<9;i++){
        for(int j =0;j<9;j++){
            if(i < 3){
                if(j < 3){
                    mp.insert({{i,j}, 0});
                }
                else if(j < 6){
                    mp.insert({{i,j}, 1});
                }
                else {
                    mp.insert({{i,j}, 2});
                }
            }
            else if(i < 6){
                if(j < 3){
                    mp.insert({{i,j}, 3});
                }
                else if(j < 6){
                    mp.insert({{i,j}, 4});
                }
                else {
                    mp.insert({{i,j}, 5});
                }
            }
            else{
                if(j < 3){
                    mp.insert({{i,j}, 6});
                }
                else if(j < 6){
                    mp.insert({{i,j}, 7});
                }
                else {
                    mp.insert({{i,j}, 8});
                }
            }
        }
    }    
}

void print_result(){
    int index =0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(arr[i][j] == '0'){
                cout << result[index];
                index++;
            }
            else cout << arr[i][j];
        }
        cout << '\n';
    }
    exit(0);
}

void back_tracking(int index){
    if(index == zero.size()) return ;
    
    int row = zero[index].first;
    int col = zero[index].second;
    
    // cout << row << ", " << col << '\n';
    
    for(int i =1;i<=9;i++){
        if(row_set[row].find(i) == row_set[row].end() &&
            col_set[col].find(i) == col_set[col].end() && 
            can_set[mp[{row,col}]].find(i) == can_set[mp[{row,col}]].end()
        ){
            // cout << "select : " << i << '\n';
            row_set[row].insert(i);
            col_set[col].insert(i);
            can_set[mp[{row,col}]].insert(i);
            result.push_back(i);
            if(result.size() == zero.size()){
                print_result();
            }
            
            back_tracking(index+1);
            
            row_set[row].erase(row_set[row].find(i));
            col_set[col].erase(col_set[col].find(i));
            can_set[mp[{row,col}]].erase(can_set[mp[{row,col}]].find(i));
            result.erase(result.end()-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    initial();
    
    string str;
    for(int i =0;i<9;i++){
        cin >> str;
        for(int j=0;j<9;j++){
            char a = str[j];
            if(a == '0') {zero.push_back({i,j}); continue;}
            row_set[i].insert(a-'0');
            col_set[j].insert(a-'0');
            can_set[mp[{i,j}]].insert(a-'0');
        }
        arr[i] = str;
    }
    
    // for(int i =0;i<9;i++){
    //     cout << "row_set " << i << " : ";
    //     for(int a : row_set[i]){
    //         cout << a << " ";
    //     }cout << '\n';
    //     cout << "col_set " << i << " : ";
    //     for(int a : col_set[i]){
    //         cout << a << " ";
    //     }cout << '\n';
    //     cout << "can_set " << i << " : ";
    //     for(int a : can_set[i]){
    //         cout << a << " ";
    //     }cout << '\n';
    // }
    
    back_tracking(0);
    
    return 0;
}