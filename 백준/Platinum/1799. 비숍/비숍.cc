#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool visited_diag1[20];
bool visited_diag2[20];
vector<pair<int, int>> black_nodes;
vector<pair<int, int>> white_nodes;
int max_black = 0;
int max_white = 0;

void solve(vector<pair<int, int>>& color_nodes, int index, int count, int& max_val) {
    if (index == color_nodes.size()) {
        max_val = max(max_val, count);
        return;
    }

    auto& node = color_nodes[index];
    int r = node.first;
    int c = node.second;

    if (!visited_diag1[r + c] && !visited_diag2[r - c + n - 1]) {
        visited_diag1[r + c] = true;
        visited_diag2[r - c + n - 1] = true;
        
        solve(color_nodes, index + 1, count + 1, max_val);
        
        visited_diag1[r + c] = false;
        visited_diag2[r - c + n - 1] = false;
    }
    solve(color_nodes, index + 1, count, max_val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int can_place;
            cin >> can_place;
            if (can_place == 1) {
                if ((i + j) % 2 == 0) {
                    black_nodes.push_back({i, j});
                } else {
                    white_nodes.push_back({i, j});
                }
            }
        }
    }

    solve(black_nodes, 0, 0, max_black);
    solve(white_nodes, 0, 0, max_white);

    cout << max_black + max_white << endl;

    return 0;
}