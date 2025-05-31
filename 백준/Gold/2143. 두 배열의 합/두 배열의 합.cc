#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, m;
    cin >> t >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) cin >> arr1[i];
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) cin >> arr2[i];
    vector<int> sum1, sum2;

    for(int i=0;i<n;++i){
        int curr = 0;
        for(int j=i;j<n;++j){
            curr += arr1[j];
            sum1.push_back(curr);
        }
    }
    for(int i=0;i<m;++i){
        int curr = 0;
        for(int j=i;j<m;++j){
            curr += arr2[j];
            sum2.push_back(curr);
        }
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());

    ll result = 0;
    int p1 = 0, p2 = sum2.size()-1;
    while(p1 < sum1.size() && p2 >= 0){
        int a = sum1[p1], b = sum2[p2];
        int s = a + b;
        if(s == t){
            ll cnt1 = 0, cnt2 = 0;
            while(p1 < sum1.size() && sum1[p1]==a) ++cnt1, ++p1;
            while(p2 >= 0 && sum2[p2]==b) ++cnt2, --p2;
            result += cnt1 * cnt2;
        }
        else if(s < t) ++p1;
        else --p2;
    }
    cout << result << '\n';
    return 0;
}