#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void explore(const vector<vector<int>>& c, vector<bool>& v, int hub, int& count) {
	for (int j = 0; j < c[hub].size(); j++) {
		if (v[c[hub][j]] == false) {
			v[c[hub][j]] = true;
			count--;
			explore(c, v, c[hub][j], count);
		}
	}
}

void solve() {
	int n;
	cin >> n;

	vector<int> p(n);
	vector<bool> v(n, false);
	vector<vector<int>> c(n);

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p[i] > p[j]) {
				c[i].push_back(j);
				c[j].push_back(i);
			}
		}
	}

	int count = n;

	for (int i = 0; i < n; i++) {
		if (v[i] == false) {
			v[i] = true;
			explore(c, v, i, count);
		}
	}

	cout << count << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}