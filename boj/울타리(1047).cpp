#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;

vector<int> getRound(vector<vector<int>> tree, int a, int b, int c, int d) {
	int minX = 1e9, minY = 1e9, maxX = 0, maxY = 0;
	for (int i = 0; i < tree.size(); i++) {
		if (i != a && i != b && i != c && i != d) continue;
		vector<int> t = tree[i];
		minX = min(minX, t[0]);
		maxX = max(maxX, t[0]);
		minY = min(minY, t[1]);
		maxY = max(maxY, t[1]);
	}
	return {minX, minY, maxX, maxY};
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N;
	cin >> N;

	tree = vector<vector<int>>(N);

	int x, y, d;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d;
		tree[i] = {x, y, d};
	}

	int result = N-1;
	for (int a = 0; a < N; a++)
		for (int b = a; b < N; b++)
			for (int c = b; c < N; c++)
				for (int d = c; d < N; d++) {
					vector<int> r= getRound(tree, a, b, c, d);
					int minX = r[0], maxX = r[2];
					int minY = r[1], maxY = r[3];
					int round = (maxX-minX+maxY-minY)*2;
					priority_queue<int> inner;
					for (int p = 0; p < N; p++) {
						// if (i <= p && p <= k) continue;
						if ( minX > tree[p][0] || maxX < tree[p][0] || minY > tree[p][1] || maxY < tree[p][1] ) {
							round -= tree[p][2];
						} else {
							inner.push(tree[p][2]);
						}
					}

					while (round > 0 && inner.size()) {
						round -= inner.top();
						inner.pop();
					}

					if (round <= 0) result = min(N-(int)inner.size(), result);
				}

	cout << result << "\n";

	return 0;
}