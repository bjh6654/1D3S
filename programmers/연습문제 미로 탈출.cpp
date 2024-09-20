#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<string> maps) {
    queue<vector<int>> q;
    vector<vector<int>> visit(maps.size(), vector<int>(maps[0].size(), 0));
    for (int r = 0; r < maps.size(); r++)
        for (int c = 0; c < maps[0].size(); c++)
            if (maps[r][c] == 'S') {
                q.push({r, c});
                visit[r][c] = 1;
            }
    
    int step = 0;
    vector<vector<int>> d({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
    char target = 'L';
    
    while (true) {
        queue<vector<int>> next;
        while (!q.empty()) {
            vector<int> top = q.front();
            q.pop();
            int r = top[0], c = top[1];

            if (maps[r][c] == target) {
                if (target == 'E') return step;
                target = 'E';
                next = queue<vector<int>>();
                next.push({r, c});
                visit = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), 0));
                visit[r][c] = 1;
                step--;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int R = r+d[i][0], C = c+d[i][1];
                if (R >= 0 && R < maps.size() && C >= 0 && C < maps[0].size()) {
                    if (maps[R][C] != 'X' && !visit[R][C]) {
                        visit[R][C] = 1;
                        next.push({R, C});
                    }                
                }
            }
        }
        if (next.empty()) break;
        q = next;
        step++;
    }
    return -1;
}