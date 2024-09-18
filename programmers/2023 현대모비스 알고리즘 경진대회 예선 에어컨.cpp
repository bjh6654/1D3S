#include <string>
#include <vector>

using namespace std;

int solution(int temp, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 1e9;
    
    vector<vector<int>> dp(1000, vector<int>(100, 1e9));
    temp += 10; t1 += 10; t2 += 10;
    temp = t2 + min(abs(temp-t1), abs(temp-t2));
    
    dp[0][temp] = 0;
    for (int r = 0; r < onboard.size()-1; r++) {
        for (int c = 0; c <= temp; c++) {
            if (onboard[r] && (c < t1 || c > t2)) continue;
            
            if (c-1 >= 0) dp[r+1][c-1] = min(dp[r][c]+a, dp[r+1][c-1]);
            
            if (c+1 <= temp) dp[r+1][c+1] = min(dp[r][c], dp[r+1][c+1]);
            
            if (c == temp) dp[r+1][c] = min(dp[r][c], dp[r+1][c]);
            else dp[r+1][c] = min(dp[r][c]+b, dp[r+1][c]);
            
        }
    }
    
    int last = 0;
    for (int i = 0; i < onboard.size(); i++) {
        if (onboard[i]) last = i;
    }
    
    for (int i = t1; i <= t2; i++) {
        answer = min(answer, dp[last][i]);
    }

    return answer;
}