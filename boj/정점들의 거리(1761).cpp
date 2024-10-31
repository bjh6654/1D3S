#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> cost, depth;
vector<vector<int>> parent;
vector<vector<vector<int>>> path;

void dfs(int idx, int sum, int d) {
  for (vector<int> p: path[idx]) {
    if (cost[p[0]] != -1) continue;
    cost[p[0]] = sum+p[1];
    parent[p[0]][0] = idx;
    depth[p[0]] = d+1;
    dfs(p[0], sum+p[1], d+1);
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  path = vector<vector<vector<int>>>(N+1);
  cost = vector<int>(N+1, -1);
  depth = vector<int>(N+1);
  parent = vector<vector<int>>(N+1, vector<int>(16, 0));
  int s, e, c;
  for (int i = 1; i < N; i++) {
    cin >> s >> e >> c;
    path[s].push_back({e, c});
    path[e].push_back({s, c});
  }

  cost[1] = 0;
  depth[1] = 0;

  dfs(1, 0, 0);

  for (int k = 1; k < 16; k++)
    for (int i = 1; i <= N; i++)
      parent[i][k] = parent[parent[i][k-1]][k-1];

  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> s >> e;
    if (depth[s] > depth[e]) swap(s, e);
    int sum = cost[s] + cost[e];
    int diff = depth[e] - depth[s];
    int n = 0;
    while (diff) {
      if (diff&1) {
        e = parent[e][n];
      }
      diff = diff>>1;
      n++;
    }
    while (s != e) {
      s = parent[s][0];
      e = parent[e][0];
    }
    sum -= cost[s]*2;

    cout << sum << "\n";
  }


	return 0;
}