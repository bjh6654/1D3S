#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<long long>> cost(n+1, vector<long long>(n+1, 1e9));
    
    for (vector<int> f: fares) {
        cost[f[0]][f[1]] = f[2];
        cost[f[1]][f[0]] = f[2];
    }
    
    for (int i = 1; i <= n; i++) cost[i][i] = 0;
    
    for (int p = 1; p <= n; p++)
        for (int r = 1; r <= n; r++)
            for (int c = 1; c <= n; c++)
                cost[r][c] = min(cost[r][p]+cost[p][c], cost[r][c]);
    
    long long result = 1e9;
    for (int i = 1; i <= n; i++) {
        result = min(cost[s][i]+cost[i][a]+cost[i][b], result);
    }
    return result;
}