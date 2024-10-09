#include <string>
#include <vector>

using namespace std;

vector<vector<int>> table;
vector<vector<int>> red, blue;
vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int answer = 1e9;

bool isRange(int r, int c) {
    if (r < 0 || r >= table.size() || c < 0 || c >= table[0].size()) return false;
    return true;
}

void dfs(int step, int rr, int rc, int br, int bc) {
    if (step >= answer) return;
    if (table[rr][rc] == 3 && table[br][bc] == 4) answer = min(step, answer);
    
    if (table[rr][rc] == 3) {
        for (int b = 0; b < 4; b++) {
            int BR = br+d[b][0], BC = bc+d[b][1];
            if (BR == rr && BC == rc) continue;
            if (!isRange(BR, BC) || table[BR][BC] == 5 || blue[BR][BC]) continue;
            blue[BR][BC] = 1;
            dfs(step+1, rr, rc, BR, BC);
            blue[BR][BC] = 0;
        }
    } else if (table[br][bc] == 4) {
        for (int a = 0; a < 4; a++) {
            int RR = rr+d[a][0], RC = rc+d[a][1];
            if (RR == br && RC == bc) continue;
            if (!isRange(RR, RC) || table[RR][RC] == 5 || red[RR][RC]) continue;
            red[RR][RC] = 1;
            dfs(step+1, RR, RC, br, bc);
            red[RR][RC] = 0;
        }
    } else {
        for (int a = 0; a < 4; a++) {
            int RR = rr+d[a][0], RC = rc+d[a][1];
            if (!isRange(RR, RC) || red[RR][RC] || table[RR][RC] == 5) continue;
            for (int b = 0; b < 4; b++) {
                int BR = br+d[b][0], BC = bc+d[b][1];
                if (!isRange(BR, BC) || blue[BR][BC] || table[BR][BC] == 5) continue;
                if (BR == RR && BC == RC) continue;
                if (BR == rr && BC == rc && RR == br && RC == bc) continue;
                
                red[RR][RC] = 1; blue[BR][BC] = 1;
                dfs(step+1, RR, RC, BR, BC);
                red[RR][RC] = 0; blue[BR][BC] = 0;
            }
        }
    }
}

int solution(vector<vector<int>> maze) {    
    table = maze;
    int rr, rc, br, bc;
    for (int r = 0; r< maze.size(); r++)
        for (int c = 0; c < maze[0].size(); c++)
            if (maze[r][c] == 1) {
                rr = r; rc = c;
            } else if (maze[r][c] == 2) {
                br = r; bc = c;
            }
    red = vector<vector<int>>(maze.size(), vector<int>(maze[0].size(), 0));
    blue = vector<vector<int>>(maze.size(), vector<int>(maze[0].size(), 0));
    red[rr][rc] = 1;
    blue[br][bc] = 1;
    
    dfs(0, rr, rc, br, bc);
    
    
    return answer == 1e9 ? 0 : answer;
}