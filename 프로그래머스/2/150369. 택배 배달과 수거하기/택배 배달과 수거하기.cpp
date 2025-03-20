#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int delivery =0;
    int pickup =0;
    
    for(int i =n-1;i>=0;i--){
        int cnt=0;
        
        delivery -= deliveries[i];
        pickup -= pickups[i];
        
        while(delivery < 0 || pickup < 0){
            cnt++;
            delivery += cap;
            pickup += cap;
        }
        
        answer += (i+1) * 2 *cnt;
    }
    
    return answer;
}