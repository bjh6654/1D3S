#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> cost;
vector<int> visit;
vector<vector<int>> road;

void bfs(queue<int> q, int step) {
    queue<int> next;
    while (!q.empty()) {
        int tmp = q.front();
        cost[tmp] = step;
        q.pop();
        
        for (int d: road[tmp]) {
            if (!visit[d]) {
                visit[d] = 1;
                next.push(d);                
            }
        }
    }
    if (!next.empty()) bfs(next, step+1);
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    cost = vector<int>(n+1, -1);
    visit = vector<int>(n+1, 0);

    road = vector<vector<int>>(n+1);
        
    for (vector<int> r: roads) {
        road[r[0]].push_back(r[1]);
        road[r[1]].push_back(r[0]);
    }
    
    queue<int> q;
    q.push(destination);
    visit[destination] = 1;
    
    bfs(q, 0);

    for (int s: sources) {
        answer.push_back(cost[s]);
    }
    return answer;
}