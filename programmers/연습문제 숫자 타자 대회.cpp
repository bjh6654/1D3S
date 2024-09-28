#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string numbers) {
    int answer = 1e9;
    vector<vector<int>> keypad({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {'*', 0, '#'}
    });
    vector<vector<int>> cost(100, vector<int>(100, 0));
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 3; c++) {
            for (int tr = 0; tr < 4; tr++) {
                for (int tc = 0; tc < 3; tc++) {
                    int dist = 0;
                    if (r == tr && c == tc) dist = 1;
                    else {
                        int diffr = abs(r-tr), diffc = abs(c-tc);
                        if (diffr && diffc) {
                            int mindiff = min(diffr, diffc);
                            dist += mindiff*3;
                            diffr -= mindiff;
                            diffc -= mindiff;                            
                        }
                        dist += diffr*2;
                        dist += diffc*2;   
                    }

                    cost[keypad[r][c]][keypad[tr][tc]] = dist;
                    cost[keypad[tr][tc]][keypad[r][c]] = dist;
                }
            }
        }
    }

    vector<vector<int>> dp(numbers.size()+1, vector<int>(100, 1e9));
    dp[0][46] = 0;
    for (int i = 0; i < numbers.size(); i++) {
        int target = numbers[i] - '0';
        for (int n = 0; n <= 98; n++) {
            if (dp[i][n] == 1e9) continue;
            int left = n/10, right = n%10;
            if (left == right) continue;
            if (left == target || right == target) dp[i+1][n] = min(dp[i][n]+1, dp[i+1][n]);
            else {
                int cLeft = target*10+right;
                int cRight = left*10+target;
                dp[i+1][cLeft] = min(dp[i][n] + cost[target][left], dp[i+1][cLeft]);
                dp[i+1][cRight] = min(dp[i][n] + cost[target][right], dp[i+1][cRight]);
            }
        }
    }
    for (int i = 0; i <= 98; i++) {
        answer = min(answer, dp[numbers.size()][i]);
    }
    return answer;
}