#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<string> map;
vector<vector<int>> direct({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});

bool isRange(int r, int c) {
  if (r < 0 || r >= map.size() || c < 0 || c >= map[0].size() ) return false;
  return true;
}

bool bfs(queue<vector<int>> player, queue<vector<int>> gost) {
  queue<vector<int>> nplayer, ngost;

  while (player.size()) {
    vector<int> cur = player.front();
    player.pop();

    if (map[cur[0]][cur[1]] == 'G') continue;
    if (map[cur[0]][cur[1]] == 'D') return true;

    for (vector<int> d: direct) {
      int R = cur[0] + d[0], C = cur[1] + d[1];
      if (!isRange(R, C) || (map[R][C] != '.' && map[R][C] != 'D')) continue;
      if (map[R][C] != 'D') map[R][C] = 'N';
      nplayer.push({R, C});
    }
  }

  while (gost.size()) {
    vector<int> cur = gost.front();
    gost.pop();

    for (vector<int> d: direct) {
      int R = cur[0] + d[0], C = cur[1] + d[1];
      if (!isRange(R, C) || map[R][C] == 'G') continue;
      map[R][C] = 'G';
      ngost.push({R, C});
    }    
  }

  if (nplayer.size()) return bfs(nplayer, ngost);
  return false;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  queue<vector<int>> player, gost;
  map = vector<string>(N);
  for (int r = 0; r < N; r++) {
    cin >> map[r];
    for (int c = 0; c < M; c++) {
      if (map[r][c] == 'N') player.push({r, c});
      else if (map[r][c] == 'G') gost.push({r, c});
    }
  }

  if (bfs(player, gost)) cout << "Yes";
  else cout << "No";

	return 0;
}