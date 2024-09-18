#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> dp(100001);
    vector<long long> newType(100001);
    // new1 = 1, new2 = 2, new3 = 5, new4 = 2, new5 = 2, new6 =4, ....
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    newType[1] = 1;
    newType[2] = 2;
    newType[3] = 5;
    for (int i = 4; i <= n; i++) {
        int x = 1;
        newType[i] = i%3 ? 2 : 4;
        dp[i] += newType[i];
        while (i-x > 0) {
            dp[i] += dp[i-x]*newType[x];
            x++;
        }
        dp[i] %= 1000000007;
    }
    return dp[n];
}