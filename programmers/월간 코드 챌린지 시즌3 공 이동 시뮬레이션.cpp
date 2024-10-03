#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
    
    reverse(queries.begin(), queries.end());
    int ex = x, ey = y;
    for (vector<int> q: queries) {
        if (q[0] == 0) {
            ey = min(ey+q[1], m-1);
            if (y != 0) {
                if (y+q[1] >= m) return 0;
                y = min(y+q[1], m-1);
            }
        } else if (q[0] == 1) {
            y = max(y-q[1], 0);
            if (ey != m-1) {
                if (ey-q[1] < 0) return 0;
                ey = max(ey-q[1], 0);
            }
        } else if (q[0] == 2) {
            ex = min(ex+q[1], n-1);
            if (x != 0) {
                if (x+q[1] >= n) return 0;
                x = min(x+q[1], n-1);
            }
        } else if (q[0] == 3) {
            x = max(x-q[1], 0);
            if (ex != n-1) {
                if (ex-q[1] < 0) return 0;
                ex = max(ex-q[1], 0);
            }
        }
    }
    
    return (long long)(ex-x+1)*(long long)(ey-y+1);
}


// 33, 34 틀림 >> 공의 가능한 위치에서 이동하려는 방향에 붙어있지 않은 경우
// 해당 쿼리로 위치에 도달할 수 없는(불가능한) 경우가 발생. return 0;