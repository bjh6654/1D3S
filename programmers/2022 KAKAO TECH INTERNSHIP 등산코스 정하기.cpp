#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> peak;
vector<int> start;
vector<vector<vector<int>>> map;
vector<int> cost;
vector<int> result({50001, 100000000});

void bfs(queue<vector<int>> q) {
    queue<vector<int>> next;
    while (!q.empty()) {
        vector<int> tmp = q.front();
        q.pop();
        if (peak[tmp[0]]) {
            if (result[1] > tmp[1]) result = tmp;
            else if (result[1] == tmp[1] && result[0] > tmp[0]) result = tmp;
            continue;
        }
        
        for (vector<int> m: map[tmp[0]]) {
            int d = m[0], w = max(m[1], tmp[1]);
            if (start[d]) continue;
            if (cost[d] > w) {
                cost[d] = w;
                next.push({d, cost[d]});
            }
        }
    }
    if (!next.empty()) bfs(next);
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    peak = vector<int>(n+1, 0);
    start = vector<int>(n+1, 0);
    map = vector<vector<vector<int>>>(n+1);
    cost = vector<int>(n+1, 1e9);
    for (int i: gates) start[i] = 1;
    for (int i: summits) peak[i] = 1;
    for (vector<int> p: paths) {
        map[p[0]].push_back({p[1], p[2]});
        map[p[1]].push_back({p[0], p[2]});
    }
    
    queue<vector<int>> q;
    for (int i: gates) {
        q.push({i, 0});
    }
    bfs(q);
    return result;
}