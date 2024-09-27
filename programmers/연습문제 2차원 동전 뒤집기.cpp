#include <string>
#include <vector>

using namespace std;

vector<vector<int>> b;
vector<vector<int>> t;
vector<int> result;

void reverseCoin(vector<vector<int>>& table, int i) {
    if (i < table.size())
        for (int c = 0; c < table[0].size(); c++)
            table[i][c] ^= 1;
    else
        for (int r = 0; r < table.size(); r++)
            table[r][i-table.size()] ^= 1;
}

bool isSame(vector<vector<int>> table, vector<vector<int>> t) {
    for (int r = 0; r < table.size(); r++)
        for (int c = 0; c < table[0].size(); c++)
            if (table[r][c] != t[r][c]) return false;
    return true;
}

int dfs(int d, int reverse) {
    if (d == b.size()+b[0].size()) {
        vector<vector<int>> table = b;
        for (int i = 0; i < result.size(); i++)
            if (result[i]) reverseCoin(table, i);
        if (isSame(table, t)) return reverse;
        return 1e9;
    }
    
    int count = 1e9;
    result[d] = 0;
    count = min(count, dfs(d+1, reverse));
    result[d] = 1;
    count = min(count, dfs(d+1, reverse+1));
    return count;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 0;
    b = beginning;
    t = target;
    result = vector<int>(b.size()+b[0].size(), 0);
    
    answer = dfs(0, 0);
    if (answer == 1e9) answer = -1;
    
    return answer;
}