#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(queue<int>& q, vector<vector<int>>& path, vector<int>& visit) {
  int size = q.size();
  if (size == 1) return q.front();

  queue<int> next;
  while (q.size()) {
    int cur = q.front();
    q.pop();

    for (int e: path[cur]) {
      if (visit[e]) continue;
      visit[e] = 1;
      next.push(e);
    }
  }

  if (next.size() != 1 && (double)next.size() != (double)size/2) return 0;
  else return bfs(next, path, visit);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  int s, e;
  vector<vector<int>> path(N+1);
  for (int i = 1; i < N; i++) {
    cin >> s >> e;
    path[s].push_back(e);
    path[e].push_back(s);
  }

  queue<int> leaf;
  vector<int> visit(N+1, 0);
  for (int i = 1; i <= N; i++) {
    if (path[i].size() != 1 && path[i].size() != 3) {
      cout << -1 << "\n";
      return 0;
    }
    if (path[i].size() == 1) {
      visit[i] = 1;
      leaf.push(i);
    }
  }

  int a = bfs(leaf, path, visit);

  if (!a) cout << -1 << "\n";
  else {
    cout << 1 << "\n";
    cout << a << "\n";
  }

	return 0;
}