#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    vector<int> dp(2*n+2);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    if (tops[0]) dp[2] += 1;
    for (int i = 3; i <= 2*n+1; i++) {
        dp[i] += dp[i-2];
        dp[i] += dp[i-1];
        if (!(i%2) && tops[i/2-1]) dp[i] += dp[i-1];
        dp[i] %= 10007;
    }
    return dp[2*n+1];
}