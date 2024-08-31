#include <iostream>
#include <algorithm>

using namespace std;

int a,b;

int max_gongyak(){
    int temp = max(a,b);
    int divide = min(a,b);
    
    while(temp % divide != 0){
        int next_divide = temp % divide;
        temp = divide;
        divide = next_divide;
    }
    
    return divide;
}

int min_gongbae(){
    int a_index=1;
    int b_index=1;
    while(true){
        if(a * a_index == b * b_index) return a*a_index;
        else if(a*a_index < b*b_index) a_index++;
        else b_index++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> a >> b;
    
    cout << max_gongyak() << '\n';
    cout << min_gongbae();
    
    return 0;
}