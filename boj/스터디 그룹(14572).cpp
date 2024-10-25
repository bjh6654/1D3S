#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> person;
vector<vector<int>> tree;

vector<int> makeTree(int s, int e, int node) {
	if (s >= e) return tree[node] = {person[s][1], person[s][1]};

	int mid = s + (e-s)/2;
	vector<int> left = makeTree(s, mid, node*2);
	vector<int> right = makeTree(mid+1, e, node*2+1);

	return tree[node] = {left[0]|right[0], left[1]&right[1]};
}

vector<int> searchTree(int s, int e, int a, int b, int node) {
	if (s > b || e < a) return {0, (1<<30)-1};
	if (a <= s && e <= b) return tree[node];

	int mid = s + (e-s)/2;
	vector<int> left = searchTree(s, mid, a, b, node*2);
	vector<int> right = searchTree(mid+1, e, a, b, node*2+1);

	return {left[0]|right[0], left[1]&right[1]};
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N, K, D;
	cin >> N >> K >> D;

	person = vector<vector<int>>(N);
	int algo, ability, algorithm;
	for (int i = 0; i < N; i++) {
		cin >> algorithm >> ability;
		int algos = 0;
		for (int a = 0; a < algorithm; a++) {
			cin >> algo;
			algos += 1<<(algo-1);
		}
		person[i] = {ability, algos};
	}

	sort(person.begin(), person.end());

	tree = vector<vector<int>>(N*4);

	makeTree(0, N-1, 1);

	int b = 0;
	int result = 0;
	for (int a = 0; a < N; a++) {
		while (b+1 < N && person[b+1][0]-person[a][0] <= D) b++;
		if (a <= b) {
			vector<int> tmp = searchTree(0, N-1, a, b, 1);
			int al = tmp[0] - tmp[1];
			int count = 0;
			while (al) {
				count += al%2;
				al /= 2;
			}
			result = max(count*(b-a+1), result);
		}
	}

	cout << result << "\n";

	return 0;
}