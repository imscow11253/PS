#include <iostream>
#include <vector>
using namespace std;

int N, W, T, K;
int ans = 0;
void func(vector<int> VEC, int curTime, int idx) {
	if (curTime == T) {
		int cnt = 0;
		for (auto x : VEC) {
			if (x) cnt++;
		}
		if (cnt >= K) ans++;
	}
	else {
		vector<int> diff(N), vec = VEC;
		for (int i = 0; i < N; i++) {
			diff[i] = 3;
			if (i > 0) {
				if (vec[i - 1]) diff[i]--;
			}
			if (i < N - 1) {
				if (vec[i + 1]) diff[i]--;
			}
		}
		for (int i = 0; i < N; i++) {
			vec[i] -= diff[i];
			vec[i] = max(vec[i], 0);
		}
		vec[idx] = VEC[idx];
		func(vec, curTime + 1, idx);

		idx--;
		vec = VEC;
		if (idx > -1) {
			for (int i = 0; i < N; i++) {
				diff[i] = 3;
				if (i > 0) {
					if (vec[i - 1]) diff[i]--;
				}
				if (i < N - 1) {
					if (vec[i + 1]) diff[i]--;
				}
			}
			for (int i = 0; i < N; i++) {
				vec[i] -= diff[i];
				vec[i] = max(vec[i], 0);
			}
			vec[idx] = VEC[idx];
			func(vec, curTime + 1, idx);
		}

		idx += 2;
		vec = VEC;
		if (idx < N) {
			for (int i = 0; i < N; i++) {
				diff[i] = 3;
				if (i > 0) {
					if (vec[i - 1]) diff[i]--;
				}
				if (i < N - 1) {
					if (vec[i + 1]) diff[i]--;
				}
			}
			for (int i = 0; i < N; i++) {
				vec[i] -= diff[i];
				vec[i] = max(vec[i], 0);
			}
			vec[idx] = VEC[idx];
			func(vec, curTime + 1, idx);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> W >> T >> K;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		vec.emplace_back(x);
	}

	vector<int> diff(N);
	for (int i = 0; i < N; i++) {
		diff[i] = 3;
		if (i > 0) {
			if (vec[i - 1]) diff[i]--;
		}
		if (i < N - 1) {
			if (vec[i + 1]) diff[i]--;
		}
	}
	for (int i = 0; i < N; i++) {
		vec[i] -= diff[i];
		vec[i] = max(vec[i], 0);
	}

	func(vec, 1, W);

	cout << ans;
}