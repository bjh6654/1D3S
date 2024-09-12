#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

vector<vector<int>> childs;

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    queue<vector<int>> q;
    childs = vector<vector<int>>(info.size(), vector<int>({}));
    for (vector<int> edge: edges) {
        childs[edge[0]].push_back(edge[1]);
    }
    
    q.push({0, !info[0], info[0], 0});
    
    while (!q.empty()) {
        vector<int> e = q.front();
        q.pop();
        if (e[1] <= e[2]) continue;
        
        answer = max(answer, e[1]);
        
        int avail = 0;
        for (int i: childs[e[0]]) {
            avail += 1<<i;
        }
        
        for (int i = 0; i < info.size(); i++) {
            if ( (e[3]+avail) & (1<<i) ) {
                q.push({i, e[1]+!info[i], e[2]+info[i], e[3]+avail-(1<<i)});
            }
        }
    }
    

    return answer;
}

// 2024-09-12