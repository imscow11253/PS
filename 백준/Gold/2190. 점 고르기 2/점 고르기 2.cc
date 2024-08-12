#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long a, b;
    cin >> n >> a >> b;
    
    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    int max_count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long x1 = points[i].first;
            long long y1 = points[j].second;
            
            int count = 0;
            for (int k = 0; k < n; k++) {
                long long x2 = points[k].first;
                long long y2 = points[k].second;
                
                if (x2 >= x1 && x2 <= x1 + a && y2 >= y1 && y2 <= y1 + b) {
                    count++;
                }
            }
            if (count > max_count) {
                max_count = count;
            }
        }
    }
    
    cout << max_count << '\n';
    return 0;
}