#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    queue<vector<int>> q;
    
    int idx = routes[0][1];
    answer = 1;
    for (vector<int> r: routes) {
        if (idx < r[0]) {
            answer++;
            idx = r[1];
        } else if (r[1] < idx) {
            idx = r[1];
        }
    }
    
    return answer;
}