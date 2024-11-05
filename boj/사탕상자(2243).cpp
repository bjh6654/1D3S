#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num(1000001, 0), tree(4000001, 0), pos(1000001);

int makeTree(int s, int e, int node) {
  if (s >= e) {
    pos[s] = node;
    return tree[node] = num[s];
  }

  int mid = s + (e-s)/2;
  return tree[node] = makeTree(s, mid, node*2) + makeTree(mid+1, e, node*2+1);
}

int searchTree(int s, int e, int a, int b, int node) {
  if (b < s || e < a) return 0;
  if (a <= s && e <= b) return tree[node];

  int mid = s + (e-s)/2;
  return searchTree(s, mid, a, b, node*2)+searchTree(mid+1, e, a, b, node*2+1);
}

void updateTree(int node, int v) {
  while (node) {
    tree[node] += v;
    node /= 2;
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  makeTree(1, 1000000, 1);

  vector<int> answer;

  int inst, B, C;
  for (int i = 0; i < N; i++) {
    cin >> inst;
    if (inst == 1) {
      cin >> B;
      int left = 1, right = 1000000;
      while (left < right) {
        int check = left + (right-left)/2;
        int result = searchTree(1, 1000000, 1, check, 1);
        if (result < B) {
          left = check+1;
        } else {
          right = check;
        }
      }
      answer.push_back(left);
      num[left]--;
      updateTree(pos[left], -1);
    } else {
      cin >> B >> C;
      num[B] += C;
      updateTree(pos[B], C);
    }
  }

  for (int i: answer) cout << i << "\n";

	return 0;
}