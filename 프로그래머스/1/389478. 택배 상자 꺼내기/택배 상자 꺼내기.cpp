#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    int remain_box_num = n - num;
    int direction = (num/w)%2 == 1 ? -1 : 1;
    
    int endPoint = num%w == 0 ? 1 : 0;
    int left_remain = num - ((num/w- endPoint) * w + 1);
    int right_remain = ((num/w- endPoint) * w) + w - num;
    
    if(endPoint ==1){
        direction *= -1;
    }
    
    cout << left_remain << " " << right_remain << '\n';
    
    if(direction == -1){
        int temp = left_remain;
        left_remain = right_remain;
        right_remain = temp;
    }
    
    cout << left_remain << " " << right_remain << '\n';
    int cur_box_num = num;
    while(true){
        cout << cur_box_num << '\n';
        
        // + 방향
        if(direction == 1){
            if(right_remain*2 + 1 + cur_box_num > n){
                break;
            }
            cur_box_num += right_remain*2 + 1;
            answer++;
            direction *= -1;
        }
        // - 방향
        else{
            if(left_remain*2 + 1 + cur_box_num > n){
                break;
            }
            cur_box_num += left_remain*2 + 1;
            answer++;
            direction *= -1;
        }
    }
    
    return answer +1;
}