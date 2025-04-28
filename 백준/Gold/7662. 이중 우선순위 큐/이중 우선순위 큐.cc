#include <iostream>
#include <set>

using namespace std;

multiset<int> st;

void insert(int value){
    st.insert(value);
}

void delete_max(){
    if(!st.empty()) st.erase(prev(st.end()));
}

void delete_min(){
    if(!st.empty()) st.erase(st.begin());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    int q;
    while(t--){
        cin >> q;
        char oper; int value;
        st.clear();
        while(q--){
            cin >> oper >> value;
            switch(oper){
                case 'I':
                    insert(value);
                    break;
                case 'D':
                    if(value == 1) delete_max();
                    else delete_min();
                    break;
            }
        }
        if(st.empty()) cout << "EMPTY" <<'\n';
        else{
            cout << *st.rbegin() << " "<< *st.begin() << '\n';
        }
    }
    
    return 0;
}