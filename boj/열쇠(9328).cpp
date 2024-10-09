#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

bool isRange(int r, int c, int n, int m) {
  if ( r < 0 || r >= n || c < 0 || c >= m) return false;
  return true;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  cin >> test;

  while (test--) {
    int n, m;
    cin >> n >> m;
    vector<string> map(n, "");
    vector<vector<int>> visit(n, vector<int>(m, 0));
    vector<vector<vector<int>>> avail(128);
    vector<int> keys(128, 0);

    for (int i = 0; i < n; i++) cin >> map[i];

    string key;
    cin >> key;

    if (key != "0")
      for (char c: key)
        keys[c] = 1;
    
    queue<vector<int>> q;
    for (int r = 0; r < n; r++)
      for (int c = 0; c < m; c++) {
        if (r != 0 && r != n-1 && c != 0 && c != m-1) continue;
        if (map[r][c] == '*') continue;
        
        if (isupper(map[r][c])) {
          avail[map[r][c]].push_back({r, c});
          visit[r][c] = 1;
        } else if (islower(map[r][c])) {
          q.push({r, c});
          visit[r][c] = 1;
          keys[map[r][c]] = 1;
        } else {
          q.push({r, c});
          visit[r][c] = 1;
        }
      }
    
    for (int i = 'a'; i <= 'z'; i++)
      if (keys[i]) {
        for (vector<int> loc: avail[toupper(i)])
          q.push(loc);
        avail[toupper(i)].clear();
      }
    
    vector<vector<int>> direct = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int answer = 0;
    while (!q.empty()) {
      vector<int> loc = q.front();
      q.pop();

      if (map[loc[0]][loc[1]] == '$') answer++;

      for (vector<int> d: direct) {
        int R = loc[0]+d[0], C = loc[1]+d[1];

        if (!isRange(R, C, n, m) || map[R][C] == '*' || visit[R][C]) continue;
        visit[R][C] = 1;
        if (isupper(map[R][C])) {
          if (keys[tolower(map[R][C])]) {
            q.push({R, C});
          } else {
            avail[map[R][C]].push_back({R, C});
          }
        } else if (islower(map[R][C])) {
          q.push({R, C});
          keys[map[R][C]] = 1;
          for (vector<int> loc: avail[toupper(map[R][C])]) {
            q.push(loc);
          }
          avail[toupper(map[R][C])].clear();
        } else {
          q.push({R, C});
        }
      }
    }
    cout << answer << "\n";
  }
  
  return 0;
}
