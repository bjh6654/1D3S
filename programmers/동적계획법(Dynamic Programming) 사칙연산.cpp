#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> calc(vector<int>& n1, string& op, vector<int>& n2) {
    if (op == "+") return {n1[0]+n2[0], n1[1]+n2[1]};
    return {n1[0]-n2[1], n1[1]-n2[0]};
}

int solution(vector<string> arr)
{
    vector<vector<vector<int>>> dp(arr.size(), vector<vector<int>>(arr.size(), vector<int>({(int)1e9, (int)-1e9})));
    for (int i = 0; i < arr.size(); i+=2) dp[i][i] = {stoi(arr[i]), stoi(arr[i])};

    for (int r = 2; r < arr.size(); r+=2) {
        for (int i = 0; i+r < arr.size(); i+=2) {
            int add = r;
            while (add >= 2) {
                vector<int> result = calc(dp[i][i+add-2], arr[i+add-1], dp[i+add][i+r]);
                dp[i][i+r][0] = min(result[0], dp[i][i+r][0]);
                dp[i][i+r][1] = max(result[1], dp[i][i+r][1]);
                add-=2;
            }
        }
    }


    return dp[0][arr.size()-1][1];
}