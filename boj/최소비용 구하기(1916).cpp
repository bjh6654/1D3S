#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<vector<int>>> path(n+1);
  int s, e, c;
  for (int i = 0; i < m; i++) {
    cin >> s >> e >> c;
    int flag = 1;
    for (int i = 0; i < path[s].size(); i++)
      if (path[s][i][0] == e) {
        path[s][i][1] = min(c, path[s][i][1]);
        flag = 0;
        break;
      }
    if (flag)
      path[s].push_back({e, c});
  }

  vector<int> cost(n+1, 1e9);

  cin >> s >> e;
  cost[s] = 0;

  queue<vector<int>> q;
  q.push({s, 0});
  while (!q.empty()) {
    vector<int> cur = q.front();
    q.pop();
    if (cur[1] > cost[cur[0]]) continue;

    for (vector<int> p: path[cur[0]]) {
      if (cost[p[0]] > cur[1]+p[1]) {
        cost[p[0]] = cur[1]+p[1];
        q.push({p[0], cur[1]+p[1]});
      }
    }
  }

  cout << cost[e] << "\n";

  return 0;
}