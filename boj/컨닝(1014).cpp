#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> map;
vector<vector<int>> visit;
vector<vector<vector<int>>> table;
vector<vector<int>> direct({{-1, -1}, {-1, 1}, {0, 1}, {1, 1}, {1, -1}, {0, -1}});

bool isRange(int r, int c) {
  if (r < 0 || r > map.size()-1 || c < 0 || c > map[0].size()-1) return false;
  return true;
}

bool dfs(int r, int c) {
  for (vector<int> d: direct) {
    int R = r + d[0], C = c + d[1];
    if (!isRange(R, C) || map[R][C] == 'x' || visit[R][C]) continue;
    visit[R][C] = 1;
    if (table[R][C][0] == -1 || dfs(table[R][C][0], table[R][C][1])) {
      table[R][C] = {r, c};
      return true;
    }
  }
  return false;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int c;
  cin >> c;

  while (c--) {
    int n, m;
    cin >> n >> m;

    int chair = 0;
    map = vector<string>(n);
    for (int i = 0; i < n; i++) {
      cin >> map[i];
      for (int c = 0; c < m; c++)
        if (map[i][c] == '.') chair++;
    }

    table = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>({-1, -1})));
    int matched = 0;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c+=2) {
        if (map[r][c] == '.') {
          visit = vector<vector<int>>(n, vector<int>(m, 0));
          visit[r][c] = 1;
          if (dfs(r, c)) matched++;
        }
      }
    }
    cout << chair-matched << "\n";
  }

  return 0;
}
