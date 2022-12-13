#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
	int l, r;
};

void visit(const vector<edge>& e, vector<bool>& v, int n, int start) {
	v[start] = true;
	int fnd = start;
	vector<edge>::const_iterator it;
	it = find_if(e.begin(), e.end(), [fnd](edge dmy) {return dmy.l == fnd;});
	int indit = it - e.begin();

	if (it == e.end()) {
		return;
	}

	int j = 1;
	while (indit + j < e.size()) {
		if (e[indit + j].l == fnd) {
			visit(e, v, n, e[indit + j].r);
			j++;
		}
		else break;
	}

		int next = e[indit].r;

	if (v[next] == false) {
		visit(e, v, n, next);
	}
}

void solve() {
	int n;
	cin >> n;

	int* p = new int[n];
	vector<edge> e;
	vector<bool> v(n, false);

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
				edg.l = j;
				edg.r = i;
				e.push_back(edg);
			}
		}
	}

	sort(e.begin(), e.end(), [](edge a, edge b) { return a.l < b.l; });

	int count = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] == false) {
			visit(e, v, n, i);
			count++;
		}
	}

	cout << count << endl;

	delete[] p;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}