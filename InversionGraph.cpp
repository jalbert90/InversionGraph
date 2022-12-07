#include <iostream>
#include <vector>

using namespace std;

struct edge {
	int l, r;
};

void solve() {
	int n;
	cin >> n;

	int* p = new int[n];
	vector<edge> e;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p[i] > p[j]) {
				edge edg;
				edg.l = i;
				edg.r = j;
				e.push_back(edg);
			}
		}
	}

	cout << e.size();

	delete[] p;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}