#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> tree, num;
long long MAX = 1e9+7;

long long makeTree(int s, int e, int node) {
  if (s >= e) return tree[node] = num[s];

  int mid = s + (e-s)/2;
  return tree[node] = (makeTree(s, mid, node*2)*makeTree(mid+1, e, node*2+1)) % MAX;
}

long long searchTree(int s, int e, int a, int b, int node) {
  if (a <= s && e <= b) return tree[node];
  if (e < a || b < s) return 1;

  int mid = s + (e-s)/2;
  return (searchTree(s, mid, a, b, node*2)*searchTree(mid+1, e, a, b, node*2+1)) % MAX;
}

long long modifyTree(int s, int e, int a, int node) {
  if (s >= e) return tree[node] = num[s];
  if (a < s || e < a) return tree[node];

  int mid = s + (e-s)/2;
  return tree[node] = (modifyTree(s, mid, a, node*2)*modifyTree(mid+1, e, a, node*2+1)) % MAX;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, K;
  cin >> N >> M >> K;

  num = vector<long long>(N);
  for (int i = 0; i < N; i++) cin >> num[i];

  tree = vector<long long>(N*4);
  makeTree(0, N-1, 1);

  int a, b, c;
  for (int i = 0; i < M+K; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      num[b-1] = c;
      modifyTree(0, N-1, b-1, 1);
    } else {
      cout << searchTree(0, N-1, b-1, c-1, 1) << "\n";
    }
  }

	return 0;
}