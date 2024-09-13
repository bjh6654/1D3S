#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> dp;
vector<int> comb;

int dfs(int d, int k, int n, int sum) {
    int m = 1e9;
    if (d == k) {
        if (sum == n) {
            int result = 0;
            for (int i = 0; i < k; i++) {
                result += dp[i][comb[i]];
            }
            return result;
        }
        return m;
    }
    
    for (int i = 1; i <= n-k+1; i++) {
        comb[d] = i;
        m = min(dfs(d+1, k, n, sum+i), m);
    }
    return m;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    dp = vector<vector<int>>(k, vector<int>(n+1, 0));
    comb = vector<int>(k, 0);
    vector<vector<vector<int>>> req(k);
    
    for (vector<int> r: reqs) {
        req[r[2]-1].push_back({r[0], r[1]});
    }
    
    for (int t = 0; t < k; t++) {
        for (int i = 1; i <= n-k+1; i++) {
            int wait = 0;
            priority_queue<int, vector<int>, greater<int>> pq;
            
            for (vector<int> r: req[t]) {
                while (pq.size() && pq.top() <= r[0]) {
                    pq.pop();
                }
                if (pq.size() < i) {
                    pq.push(r[0]+r[1]);
                } else {
                    int top = pq.top();
                    pq.pop();
                    pq.push(top+r[1]);
                    wait += top-r[0];
                }
            }
            dp[t][i] = wait;
        }
    }
    
    answer = dfs(0, k, n, 0);
    return answer;
}