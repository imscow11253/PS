#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    long long minAbs = LONG_LONG_MAX;
    int answer[3];

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            long long sum = vec[i] + vec[left] + vec[right];
            if (abs(sum) < minAbs) {
                minAbs = abs(sum);
                answer[0] = vec[i];
                answer[1] = vec[left];
                answer[2] = vec[right];
            }
            if (sum < 0) left++;
            else if (sum > 0) right--;
            else { 
                break;
            }
        }
    }

    sort(answer, answer + 3);
    cout << answer[0] << " " << answer[1] << " " << answer[2] << "\n";

    return 0;
}