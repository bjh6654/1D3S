#include <iostream>
#include <vector>

using namespace std;

vector<int> tree(400000);
vector<int> num;

int searchTree(int s, int e, int n, int a, int b) {
  if (s > b || e < a) return 1e9;
  if (s == e) return num[s];
  if (a <= s && e <= b) return tree[n];
  int m = s + (e-s)/2;
  return min(searchTree(s, m, n*2, a, b), searchTree(m+1, e, n*2+1, a, b));
}

int makeTree(int s, int e, int n) {
  if (s == e) return tree[n] = num[s];

  int m = s + (e-s)/2;
  return tree[n] = min(makeTree(s, m, n*2), makeTree(m+1, e, n*2+1));
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  
  num = vector<int>(n);
  for (int i = 0; i < n; i++) cin >> num[i];

  makeTree(0, n-1, 1);

  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    cout << searchTree(0, n-1, 1, a-1, b-1) << "\n";
  }

  return 0;
}
