#include <string>
#include <vector>

using namespace std;

vector<int> solution(int target) {
    vector<vector<int>> dp(100100, {1000000, 0});
    
    dp[0] = {0, 0};
    for (int i = 0; i <= target; i++) {
        for (int mul = 1; mul <= 3; mul++)
            for (int s = 1; s <= 20; s++)
                if (dp[i+s*mul][0] > dp[i][0]+1)
                    dp[i+s*mul] = {dp[i][0]+1, dp[i][1]+(mul==1)};
                else if (dp[i+s*mul][0] == dp[i][0]+1)
                    dp[i+s*mul][1] = max(dp[i][1]+(mul==1), dp[i+s*mul][1]);
        if (dp[i+50][0] > dp[i][0]+1)
            dp[i+50] = {dp[i][0]+1, dp[i][1]+1};
        else if (dp[i+50][0] == dp[i][0]+1)
            dp[i+50][1] = max(dp[i+50][1], dp[i][1]+1);
    }
    
    return {dp[target][0], dp[target][1]};
}