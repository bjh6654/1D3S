#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<int> row, col;
vector<vector<int>> blank, square;

bool dfs(int idx) {
  if (idx == blank.size()) {
    return true;
  }

  for (int i = 1; i <= 9; i++) {
    int r = blank[idx][0], c = blank[idx][1];
    int bit = 1<<i;
    if (row[r]&bit || col[c]&bit || square[r/3][c/3]&bit) continue;
    row[r] += bit;
    col[c] += bit;
    square[r/3][c/3] += bit;
    map[r][c] = i;
    if (dfs(idx+1)) return true;
    row[r] -= bit;
    col[c] -= bit;
    square[r/3][c/3] -= bit;
    map[r][c] = 0;
  }
  return false;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map = vector<vector<int>>(9, vector<int>(9, 0));
  row = vector<int>(9, 0);
  col = vector<int>(9, 0);
  square = vector<vector<int>>(3, vector<int>(3, 0));

	string line;
  for (int r = 0; r < 9; r++) {
    cin >> line;
    for (int c = 0; c < 9; c++) {
      map[r][c] = line[c] -'0';

      if (map[r][c] == 0) {
        blank.push_back({r, c});
      } else {
        row[r] += 1<<map[r][c];
        col[c] += 1<<map[r][c];
        square[r/3][c/3] += 1<<map[r][c];
      }
    }
  }

  dfs(0);

  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++)
      cout << map[r][c];
    cout << "\n";
  }

	return 0;
}