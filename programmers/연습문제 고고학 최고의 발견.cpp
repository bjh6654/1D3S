#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> visit;
vector<vector<int>> table;

void spinTable(vector<vector<int>>& table, int r, int c, int count) {
    int n = table.size();
    table[r][c] = (table[r][c]+count)%4;
    if (r-1 >= 0)table[r-1][c] = (table[r-1][c]+count)%4;
    if (r+1 < n)table[r+1][c] = (table[r+1][c]+count)%4;
    if (c-1 >= 0)table[r][c-1] = (table[r][c-1]+count)%4;
    if (c+1 < n)table[r][c+1] = (table[r][c+1]+count)%4;
}

bool checkZero(vector<vector<int>> table) {
    for (int r = 0; r < table.size(); r++)
        for (int c = 0; c < table.size(); c++)
            if (table[r][c]) return false;
    return true;
}

int dfs(int d, int n) {
    if (d == n) {
        vector<vector<int>> tmp = table;
        
        int answer = 0;
        for (int a = 0; a < n; a++) {
            spinTable(tmp, 0, a, visit[a]);
            answer += visit[a];
        }
        
        for (int r = 1; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int spinCount = (4-tmp[r-1][c])%4;
                spinTable(tmp, r, c, spinCount);
                answer += spinCount;
            }
        }
        if (checkZero(tmp)) return answer;
        return 1e9;
    }
    
    int result = 1e9;
    for (int i = 0; i < 4; i++) {
        visit[d] = i;
        result = min(dfs(d+1, n), result);
    }
    return result;
}


int solution(vector<vector<int>> clocksHands) {
    table = clocksHands;
    int n = table.size();
    visit = vector<int>(n, 0);
    
    int answer = dfs(0, n);
    
    return answer;
}