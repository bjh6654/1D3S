#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> tree, lazy;
vector<long long> num;

void updateLazy(int s, int e, int node) {
	if (lazy[node]) {
		if (s != e) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		tree[node] += lazy[node]*(e-s+1);
		lazy[node] = 0;
	}
}

long long makeTree(int s, int e, int node) {
	if (s >= e) return tree[node] = num[s];

	int mid = s + (e-s)/2;
	return tree[node] = makeTree(s, mid, node*2) + makeTree(mid+1, e, node*2+1);
}

long long searchTree(int s, int e, int a, int b, int node) {
	updateLazy(s, e, node);
	if (s > b || e < a) return 0;
	if (a <= s && e <= b) return tree[node];

	int mid = s + (e-s)/2;
	return searchTree(s, mid, a, b, node*2) + searchTree(mid+1, e, a, b, node*2+1);
}

long long setLazy(int s, int e, int a, int b, int node, long long value) {
	updateLazy(s, e, node);
	if (s > b || e < a) return tree[node];
	if (a <= s && e <= b) {
		if (s < e) {
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}
		return tree[node] += value*(e-s+1);
	}

	int mid = s + (e-s)/2;
	return tree[node] = setLazy(s, mid, a, b, node*2, value) + setLazy(mid+1, e, a, b, node*2+1, value);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	num = vector<long long>(N);
	for (int i = 0; i < N; i++) cin >> num[i];

	tree = vector<long long>(4*N, 0);
	lazy = vector<long long>(4*N, 0);

	makeTree(0, N-1, 1);
	
	int inst, a, b;
	long long value;
	for (int i = 0; i < M+K; i++) {
		cin >> inst;
		if (inst == 1) {
			cin >> a >> b >> value;
			setLazy(0, N-1, a-1, b-1, 1, value);
		} else {
			cin >> a >> b;
			cout << searchTree(0, N-1, a-1, b-1, 1) << "\n";
		}
	}

	return 0;
}