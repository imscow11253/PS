#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
long long a;
vector<int> vec;

bool canPromote(int initial_ability) {
    int current_ability = initial_ability;
    long long total_score = 0;

    for (int i = 0; i < m; ++i) {
        auto index = upper_bound(vec.begin(), vec.end(), current_ability);
        if (index == vec.begin()) break;
        --index;
        int target_score = *index;
        
        total_score += target_score;
        current_ability += target_score;
        
        if (total_score >= a) return true;
    }
    return total_score >= a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> a;
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    
    int low = 0, high = vec[n - 1], answer = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPromote(mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << answer << '\n';
    return 0;
}