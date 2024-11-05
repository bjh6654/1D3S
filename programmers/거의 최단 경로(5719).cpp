#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp {
  bool operator() (vector<long long> a, vector<long long> b) {
    return a[1] > b[1];
  }
};

vector<long long> dikstra(int s, vector<vector<long long>> map) {
  vector<long long> cost(map.size(), 1e9);

  vector<vector<vector<long long>>> path(map.size());
  for (int i = 0; i < map.size(); i++)
    for (int k = 0; k < map.size(); k++)
      if (map[i][k] != 1e9) path[i].push_back({k, map[i][k]});

  priority_queue<vector<long long>, vector<vector<long long>>, cmp> q;
  q.push({s, 0});
  cost[s] = 0;

  while (q.size()) {
    vector<long long> cur = q.top();
    q.pop();
    
    if (cost[cur[0]] < cur[1]) continue;

    for (vector<long long> e: path[cur[0]]) {
      if (cur[1]+e[1] < cost[e[0]]) {
        cost[e[0]] = cur[1]+e[1];
        q.push({e[0], cost[e[0]]});
      }
    }
  }

  return cost;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<long long> answer;

  int N, M, S, D;
  while (true) {
    cin >> N >> M;
    if (!N && !M) break;
    cin >> S >> D;

    vector<vector<long long>> map(N, vector<long long>(N, 1e9));
    int u, v, p;
    for (int i = 0; i < M; i++) {
      cin >> u >> v >> p;
      map[u][v] = p;
    }

    vector<long long> cost = dikstra(S, map);

    queue<vector<long long>> bk;
    bk.push({D, cost[D]});
    while (bk.size()) {
      vector<long long> cur = bk.front();
      bk.pop();

      for (int i = 0; i < N; i++) {
        if (cur[0] == i) continue;
        if (cur[1] == cost[i] + map[i][cur[0]]) {
          bk.push({i, cur[1]-map[i][cur[0]]});
          map[i][cur[0]] = 1e9;
        }
      }
    }
    
    vector<long long> costResult = dikstra(S, map);
    if (costResult[D] == 1e9) answer.push_back(-1);
    else answer.push_back({costResult[D]});
  }

  for (long long i: answer)
    cout << i << "\n";

	return 0;
}