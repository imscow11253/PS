#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);  // 입출력 속도 향상
    cin.tie(NULL);                // cin과 cout의 묶음 해제
    
    int N;
    cin >> N;
    
    vector<pair<long long, long long>> lines(N);
    
    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        lines[i] = {x, y};
    }
    
    // 시작점을 기준으로 정렬
    sort(lines.begin(), lines.end());
    
    long long total_length = 0;
    long long current_start = lines[0].first;
    long long current_end = lines[0].second;
    
    for (int i = 1; i < N; i++) {
        long long next_start = lines[i].first;
        long long next_end = lines[i].second;
        
        if (next_start <= current_end) {
            current_end = max(current_end, next_end);
        } else {
            total_length += current_end - current_start;
            current_start = next_start;
            current_end = next_end;
        }
    }
    
    total_length += current_end - current_start;
    
    cout << total_length << "\n";
    
    return 0;
}