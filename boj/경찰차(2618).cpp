#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getDist(vector<int> a, vector<int> b) {
	return abs(a[0]-b[0]) + abs(a[1]-b[1]);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N, W;
	cin >> N >> W;

	vector<vector<int>> loc(W+1);
	int r, c;
	for (int i = 1; i <= W; i++) {
		cin >> r >> c;
		loc[i] = {r, c};
	}

	vector<vector<int>> dp(W+1, vector<int>(W+1, 1e9));
	dp[0][0] = 0;
	dp[1][0] = getDist(loc[1], {1, 1});
	dp[0][1] = getDist(loc[1], {N, N});

	for (int first = 0; first < W; first++)
		for (int second = 0; second < W; second++) {
			int step = max(first, second)+1;
			if (first == second) continue;
			vector<int> preFirst = first ? loc[first] : vector<int>({1, 1});
			vector<int> preSecond = second > 0 ? loc[second] : vector<int>({N, N});
			dp[step][second] = min(dp[first][second]+getDist(preFirst, loc[step]), dp[step][second]);
			dp[first][step] = min(dp[first][second]+getDist(preSecond, loc[step]), dp[first][step]);
		}

	int result = 1e9;
	int first = 0, second = 0;
	for (int i = 0; i < W; i++) {
		if (dp[W][i] < result) {
			result = dp[W][i];
			first = W;
			second = i;
		}
		if (dp[i][W] < result) {
			result = dp[i][W];
			first = i;
			second = W;
		}
	}

	cout << result << "\n";	

	vector<int> answer;
	while (first || second) {
		for (int pre = max(first, second)-1; pre >= 0; pre--) {
			if (pre != first &&  dp[first][second] == dp[pre][second]+getDist(pre ? loc[pre] : vector<int>({1, 1}), first ? loc[first] : vector<int>({1, 1}))) {
				first = pre;
				answer.push_back(1);
				break;
			} else if (pre != second && dp[first][second] == dp[first][pre]+getDist(pre ? loc[pre] : vector<int>({N, N}), second ? loc[second] : vector<int>({N, N}))) {
				second = pre;
				answer.push_back(2);
				break;
			}
		}
	}

	for (int i = answer.size()-1; i >= 0; i--)
		cout << answer[i] << "\n";

	return 0;
}