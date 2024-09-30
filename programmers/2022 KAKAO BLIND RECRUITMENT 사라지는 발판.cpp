#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> table;
vector<vector<int>> visit;
vector<vector<int>> d({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

bool isRange(int r, int c) {
    if (r < 0 || r >= table.size() || c < 0 || c >= table[0].size()) return false;
    return true;
}

int dfs(int step, vector<int> aloc, vector<int> bloc) {
    vector<int> loc = step%2 ? bloc : aloc;
    
    if (!table[loc[0]][loc[1]]) {
        return -step;
    }
    
    int win = 1e9;
    int lose = 0;
    for (int i = 0; i < 4; i++) {
        int R = loc[0] + d[i][0];
        int C = loc[1] + d[i][1];
        if (!isRange(R, C) || !table[R][C]) continue;
        table[loc[0]][loc[1]] = 0;
        int tmp;
        if (step%2) {
            tmp = -dfs(step+1, aloc, {R, C});
        } else {
            tmp = -dfs(step+1, {R, C}, bloc);
        }
        if (tmp > 0) win = min(win, tmp);
        else lose = abs(tmp) > abs(lose) ? tmp : lose;
        table[loc[0]][loc[1]] = 1;
    }
    if (win == 1e9 && lose == 0) return -step;
    else if (win != 1e9) return win;
    else return lose;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    table = board;
    visit = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
    
    answer = dfs(0, aloc, bloc);
    return abs(answer);
}