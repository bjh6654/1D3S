#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> sd({{-1, 0}, {0, -1}, {1, 0}, {0, 1}});

int maxSum = -1;
vector<int> steps(3);
vector<int> pos;

bool isRange(int r, int c) {
  if (r < 1 || r > 4 || c < 1 || c > 4) return false;
  return true;
}

void dfs(int r, int c, int step, int sum, vector<vector<vector<int>>> map) {
  if (step == 3) {
    if (maxSum < sum) {
      maxSum = sum;
      pos = steps;
    }
    return;
  }

  for (int i = 0; i < 4; i++) {
    int R = r+sd[i][0];
    int C = c+sd[i][1];
    if (isRange(R, C)) {
      steps[step] = i;
      vector<int> tmp = map[R][C];
      map[R][C].clear();
      dfs(R, C, step+1, sum + tmp.size(), map);
      map[R][C] = tmp;
    }
      
  }
}

vector<vector<vector<int>>> soul(102, vector<vector<int>>(5, vector<int>(5, 0)));

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int M, S;
  cin >> M >> S;

  queue<vector<int>> q, copy;
  for (int i = 0; i < M; i++) {
    int r, c, d;
    cin >> r >> c >> d;

    q.push({r, c, d});
  }

  int sr, sc;
  cin >> sr >> sc;

  vector<vector<int>> direct({{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}});
  
  while (S--) {
    vector<vector<vector<int>>> map(5, vector<vector<int>>(5));
    copy = q;
    while (!q.empty()) {
      vector<int> fish = q.front();
      q.pop();
      
      int flag = 1;
      for (int i = 0; i < 8; i++) {
        int R = fish[0]+direct[fish[2]][0];
        int C = fish[1]+direct[fish[2]][1];
        if (isRange(R, C) && (R != sr || C != sc) && !soul[S+1][R][C] && !soul[S+2][R][C]) {
          map[R][C].push_back(fish[2]);
          flag = 0;
          break;
        }
        if (fish[2] == 1) fish[2] = 8;
        else fish[2]--;
      }
      if (flag) map[fish[0]][fish[1]].push_back(fish[2]);
    }
    maxSum = -1;
    pos = {-1, -1, -1};
    dfs(sr, sc, 0, 0, map);

    if (pos[0] != -1)
      for (int i: pos) {
        sr += sd[i][0];
        sc += sd[i][1];
        if (map[sr][sc].size()) {
          soul[S][sr][sc] = 1;
        }
        map[sr][sc].clear();
      }
    
    q = copy;
    for (int r = 1; r <= 4; r++)
      for (int c = 1; c <= 4; c++)
        for (int i: map[r][c])
          q.push({r, c, i});
  }

  cout << q.size() << "\n";

  return 0;
}
