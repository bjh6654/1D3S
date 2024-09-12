#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<vector<int>> robots;
    vector<vector<int>> visit;
    
    visit = vector<vector<int>>(101, vector<int>(101, 0));
    for (int i = 0; i < routes.size(); i++) {
        vector<int> p = points[routes[i][0]-1];
        robots.push_back(p);
        routes[i].erase(routes[i].begin());
        
        if (visit[p[0]][p[1]] == 1) answer += 1;
        visit[p[0]][p[1]] += 1;
    }

    int c = 1;
    while (true) {
        visit = vector<vector<int>>(101, vector<int>(101, 0));
        
        bool flag = false;
        for (int i = 0; i < robots.size(); i++) {
            if (routes[i].size()) {
                flag = true;
                vector<int>& cur = robots[i];
                vector<int> next = points[routes[i][0]-1];
                
                if (cur[0] != next[0]) cur[0] += cur[0] < next[0] ? 1 : -1;
                else cur[1] += cur[1] < next[1] ? 1 : -1;
                
                if (cur[0] == next[0] && cur[1] == next[1]) routes[i].erase(routes[i].begin());
                
                if (visit[cur[0]][cur[1]] == 1) answer += 1;
                visit[cur[0]][cur[1]] += 1;
            }
        }
        
        // cout << "----" << c << "----\n";
        // for (vector<int> r: robots) {
        //     cout << r[0] << ", " << r[1] << "\n";
        // }
        // c++;
        if (!flag) break;
    }
    return answer;
}

// 2024-09-11