#include <string>
#include <vector>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int ralp = alp, rcop = cop;
    for (vector<int> p: problems) {
        ralp = ralp < p[0] ? p[0] : ralp;
        rcop = rcop < p[1] ? p[1] : rcop;
    }
    
    vector<vector<int>> dp(ralp+1, vector<int>(rcop+1, 1e9));
    for (int r = alp; r <= ralp; r++) {
        for (int c = cop; c <= rcop; c++) {
            dp[r][c] = r+c-alp-cop < dp[r][c] ? r+c-alp-cop : dp[r][c];
            for (vector<int> p: problems) {
                if (p[0] > r || p[1] > c) continue;
                int R = min(r+p[2], ralp);
                int C = min(c+p[3], rcop);
                dp[R][C] = min(dp[r][c]+p[4], dp[R][C]);
            }
        }
    }
    return dp[ralp][rcop];
}