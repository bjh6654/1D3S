#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(vector<int> s) {
    long long answer = 0;
    
    vector<vector<long long>> dp(s.size(), vector<long long>(2, 0));
    dp[0][0] = max(s[0], 0);
    dp[0][1] = max(-s[0], 0);
    for (int i = 0; i < s.size(); i++) {
        if (i >= 1) {
            dp[i][0] = max( max((long long)s[i], dp[i-1][1]+s[i]), 0ll );
            dp[i][1] = max( max((long long)-s[i], dp[i-1][0]-s[i]), 0ll );
        }
        answer = max(max(answer, dp[i][0]), dp[i][1]);
    }
    return answer;
}