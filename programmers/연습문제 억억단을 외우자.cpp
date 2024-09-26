#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> count(e+1, 0);
    vector<int> dp(e+1, 0);
    for (int i = 1; i <= e; i++) {
        for (int k = 1; k <= e/i; k++) {
            count[i*k] += 1;
        }
    }
    dp[e] = e;
    for (int i = e-1; i >= 1; i--) {
        if (count[dp[i+1]] <= count[i]) dp[i] = i;
        else dp[i] = dp[i+1];
    }
    for (int s: starts) {
        answer.push_back(dp[s]);
    }
    return answer;
}