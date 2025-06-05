#include <iostream>
#include <deque>

using namespace std;

int n;
int arr[1000000];
deque<int> de;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }

    int card = 1;
    int temp;
    for(int i = n-1;i>=0;i--){
        switch(arr[i]){
            case 1:
                de.push_front(card++);
                break;
            case 2:
                temp = de.front();
                de.pop_front();
                de.push_front(card++);
                de.push_front(temp);
                break;
            case 3:
                de.push_back(card++);
                break;
        }
    }
    
    for(int a : de){
        cout << a  << " ";
    }
    
    return 0;
}