#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

int getDist(int sx, int sy, int bx, int by) {
    return pow(sx-bx, 2) + pow(sy-by, 2);
}

int findShort(int m, int n, vector<int> start, vector<int> ball) {
    int mD = 1e9;
    int sx = start[0], sy = start[1], bx = ball[0], by = ball[1];
    
    if (start[1] != ball[1]) {
        mD = min(getDist(-sx, sy, bx, by), mD);
        mD = min(getDist(2*m-sx, sy, bx, by), mD);
        mD = min(getDist(sx, sy, -bx, by), mD);
        mD = min(getDist(sx, sy, 2*m-bx, by), mD);
    } else if (start[0] < ball[0]) {
        mD = min(getDist(-sx, sy, bx, by), mD);
    } else if (start[0] > ball[0]) {
        mD = min(getDist(2*m-sx, sy, bx, by), mD);
    }
    
    if (start[0] != ball[0]) {
        mD = min(getDist(sx, -sy, bx, by), mD);
        mD = min(getDist(sx, 2*n-sy, bx, by), mD);
        mD = min(getDist(sx, sy, bx, -by), mD);
        mD = min(getDist(sx, sy, bx, 2*n-by), mD);        
    } else if (start[1] < ball[1]) {
        mD = min(getDist(sx, -sy, bx, by), mD);
    } else if (start[1] > ball[1]) {
        mD = min(getDist(sx, 2*n-sy, bx, by), mD);
    }
    return mD;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (vector<int> ball: balls) {
//         int bx = ball[0], by = ball[1];
        
//         if (bx == startX) {
//             ball[0] < abs(m-ball[0]) ? ball[0] *= -1 : ball[0] += abs(m-ball[0])*2;
//         } else if (by == startY) {
//             ball[1] < abs(n-ball[1]) ? ball[1] *= -1 : ball[1] += abs(n-ball[1])*2;
//         } else {
//             answer.push_back(findShort(m, n, {startX, startY}, ball));
//             continue;
//         }
//         answer.push_back(pow(startX-ball[0], 2)+pow(startY-ball[1], 2));
        answer.push_back(findShort(m, n, {startX, startY}, ball));
    }
    return answer;
}