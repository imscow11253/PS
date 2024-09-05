#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool arr[501]={};
bool sosu[1000001]={};
set<int> st = {9,81,65,61,37,58,89,145,42,20,4,16};

int cal(int num){
    string str = to_string(num);
    int sum=0;
    for(char a : str){
        int index = a - '0';
        sum += index*index;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i =2;i<1000000;i++){
        int index=2;
        int temp =i*index;
        while(temp <= 1000000){
            sosu[temp] = 1;
            temp += i;
        }
    }
    
    int n;
    cin >> n;
    
    arr[0]=true;
    arr[2]=true;
    
    for(int i=3;i<=n;i++){
        if(sosu[i]) continue;
        
        vector<int> vec;
        int temp =i;
        while(true){
            temp = cal(temp);
            if(temp ==1) {
                cout << i << '\n';
                break;
            }
            if(st.find(temp) == st.end()){
                vec.push_back(temp);
            }
            else{
                for(int a : vec) st.insert(a);
                break;
            }
        }
        
    }
    
    return 0;
}