#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string board;
    cin >> board;
    
    int index = 0;

    for (int i = 0; i < board.size(); i++) {
        if (board[i] == 'X') {
            index++;
        } else {
            if (index % 2 == 1) {
                cout << -1; 
                return 0;
            }
            index = 0;
        }
    }

    if (index % 2 == 1) {
        cout << -1;
        return 0;
    }

    index = 0;
    for (int i = 0; i < board.size(); i++) {
        if (board[i] == 'X') {
            index++;
        } else {
            while (index >= 4) {
                cout << "AAAA";
                index -= 4;
            }
            if (index == 2) {
                cout << "BB";
            }
            index = 0;
            cout << "."; 
        }
    }

    if (index > 0) {
        while (index >= 4) {
            cout << "AAAA";
            index -= 4;
        }
        if (index == 2) {
            cout << "BB";
        }
    }

    return 0;
}