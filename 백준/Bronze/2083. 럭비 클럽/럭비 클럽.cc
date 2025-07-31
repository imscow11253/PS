#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string name;
    int age, weight;
    cin >> name >> age >> weight;
    
    while(name != "#" || age != 0 || weight != 0){
        if(age > 17){
            cout << name << " " << "Senior\n";
        }
        else if(weight>= 80){
            cout << name << " " << "Senior\n";
        }
        else cout << name << " " << "Junior\n";
        cin >> name >> age >> weight;
    }
    
    
    return 0;
}