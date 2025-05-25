#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

string arr[8];

long double combination(int n, int k) {
    long double res = 1.0;
    for(int i=1;i<=k;i++) {
        res *= (long double)(n-i+1)/i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int block_num = 0;
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
        for (char a : arr[i]) if (a == 'O') block_num++;
    }

    int max_value = 0;
    vector<pair<int,int>> v;
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            int value = 0;
            value += (arr[i - 1][j - 1] == 'O');
            value += (arr[i - 1][j] == 'O');
            value += (arr[i][j - 1] == 'O');
            value += (arr[i][j] == 'O');
            if (max_value < value) {
                max_value = value;
                v.clear();
                v.push_back({i,j});
            } else if (max_value == value) {
                v.push_back({i,j});
            }
        }
    }
    long double survive = 0;
    if (block_num >= 4 && max_value>=1 && block_num>=max_value){
        long double comb_all = combination(block_num,4);
        long double comb_miss = combination(block_num-max_value,4);
        long double miss = comb_miss/comb_all;
        survive = 1.0 - miss;
    } else {
        survive = 1.0;
    }

    cout << v[0].first << " " << v[0].second << '\n';
    cout << fixed << setprecision(14) << survive << '\n';
}