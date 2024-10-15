#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	if (a[1] == b[1]) return a[0] < b[0];
	return a[1] < b[1];
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> p(n);
	int s, e;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		if (s >= e) swap(s, e);
		p[i] = {s, e};
	}

	int d;
	cin >> d;

	sort(p.begin(), p.end(), cmp);

	int result = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (vector<int> l: p) {
		q.push(l[0]);
		while (q.size() && q.top()+d < l[1]) q.pop();
		result = max((int)q.size(), result);
	}

	cout << result << "\n";

	return 0;
}