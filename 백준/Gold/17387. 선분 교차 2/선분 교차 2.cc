#include <iostream>
#include <algorithm>

using namespace std;

pair<long long,long long> points[4];

int ccw(int index, int index2, int index3){
    pair<long long,long long> point_1 = points[index];
    pair<long long,long long> point_2 = points[index2];
    pair<long long,long long> point_3 = points[index3];
    
    long long result = (point_1.first * point_2.second) + (point_2.first * point_3.second) + (point_3.first * point_1.second);
    result -= (point_1.second * point_2.first) + (point_2.second * point_3.first) + (point_3.second * point_1.first);
    
    return (result <=0 ) ? (result ==0) ? 0 : -1 : 1;
}

int check_cross(){
    int a = ccw(0,1,2);
    int b = ccw(0,1,3);
    int c = ccw(2,3,0);
    int d = ccw(2,3,1);
    
    // cout << a << " " << b << " " << c << " " << d << '\n';
    
    if(a*b <= 0 && c*d <= 0){
        if(a ==0 && b ==0 && c ==0 && d==0){
            // 두 선분이 평행하더라도 겹치는지 확인해야 한다.
            if(points[0].first == points[2].first){
                if(points[0].second > points[1].second) swap(points[0], points[1]);
                if(points[2].second > points[3].second) swap(points[2], points[3]);
                return (points[0].second <= points[3].second && points[2].second <= points[1].second);
            }
            if(points[0].first > points[1].first) swap(points[0], points[1]);
            if(points[2].first > points[3].first) swap(points[2], points[3]);
            return (points[0].first <= points[3].first && points[2].first <= points[1].first);
        }
        return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i=0;i<4;i++){
        long long x,y;
        cin >> x >> y;
        points[i] = {x,y};
    }
    
    cout << check_cross();
    
    return 0;
}