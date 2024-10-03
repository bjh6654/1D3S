#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
vector<int> visit;

int bfs(queue<int> q) {
    int size = q.size();
    queue<int> next;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        
        for (int i: map[tmp]) {
            if (visit[i]) continue;
            visit[i] = 1;
            next.push(i);
        }
    }
    if (next.empty()) return size;
    return bfs(next);
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    visit = vector<int>(n+1, 0);
    map = vector<vector<int>>(n+1);
    for (vector<int> e: edge) {
        map[e[0]].push_back(e[1]);
        map[e[1]].push_back(e[0]);
    }
    
    queue<int> q;
    q.push(1);
    visit[1] = 1;
    
    answer = bfs(q);
    
    return answer;
}