#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> num;

vector<int> makeTree(int s, int e, int node) {
	if (s == e) return tree[node] = {num[s], num[s]};

	int mid = s + (e-s)/2;
	vector<int> left = makeTree(s, mid, node*2);
	vector<int> right = makeTree(mid+1, e, node*2+1);
	return tree[node] = {min(left[0], right[0]), max(left[1], right[1])};
}

vector<int> searchTree(int s, int e, int a, int b, int node) {
	if (b < s || a > e) return {(int)1e9, (int)-1e9};
	if (a <= s && e <= b) return tree[node];
	if (s == e) return tree[node];

	int mid = s + (e-s)/2;
	vector<int> left = searchTree(s, mid, a, b, node*2);
	vector<int> right = searchTree(mid+1, e, a, b, node*2+1);
	return {min(left[0], right[0]), max(left[1], right[1])};
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	num = vector<int>(N);
	tree = vector<vector<int>>(N*4);
	for (int i = 0; i < N; i++) cin >> num[i];

	makeTree(0, N-1, 1);
	
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vector<int> result = searchTree(0, N-1, a-1, b-1, 1);
		cout << result[0] << " " << result[1] << "\n";
	}
	

	return 0;
}