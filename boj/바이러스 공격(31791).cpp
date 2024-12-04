#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int TG, TB, X, B;
vector<string> table;

vector<vector<int>> direct({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});

bool isRange(int r, int c) {
  if (0 > r || r >= N || 0 > c || c >= M) return false;
  return true; 
}

struct cmp {
  bool operator() (vector<int> a, vector<int> b) {
    return a[2] > b[2];
  }
};

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  cin >> TG >> TB >> X >> B;

  priority_queue<vector<int>, vector<vector<int>>, cmp> q;
  table = vector<string>(N);
  vector<vector<int>> cost(N, vector<int>(M, 1e9));

  for (int r = 0; r < N; r++) {
    cin >> table[r];
    for (int c = 0; c < M; c++)
      if (table[r][c] == '*') {
        q.push({r, c, 0});
        cost[r][c] = 0;
      }
  }

  while (q.size()) {
    vector<int> cur = q.top();
    q.pop();

    for (vector<int> d: direct) {
      int R = cur[0] + d[0], C = cur[1] + d[1];
      if (isRange(R, C)) {
        int add = table[R][C] == '#' ? TB+1 : 1;
        if (cost[R][C] > cur[2]+add) {
          cost[R][C] = cur[2]+add;
          if (cost[R][C] < TG) q.push({R, C, cost[R][C]});
        }
      }
    }
  }

  vector<vector<int>> answer;
  bool flag = true;
  for (int r = 0; r < N; r++)
    for (int c = 0; c < M; c++)
      if (cost[r][c] > TG) answer.push_back({r+1, c+1});
  
  if (answer.size()) {
    for (vector<int> a: answer) cout << a[0] << " " << a[1] << "\n";
  } else {
    cout << -1 << "\n";
  }
  
	return 0;
}