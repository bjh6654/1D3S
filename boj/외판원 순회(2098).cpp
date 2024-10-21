#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> table;

int answer = 1e9;

int dfs(int d, int idx, int sum, int visited) {
	if (d == table.size()) {
		if (table[idx][0]) {
			answer = min(sum+table[idx][0], answer);
			return sum+table[idx][0];
		}
		return -1;
	}
	if (dp[idx][visited] == -1) return -1;
	if (dp[idx][visited] != 1e9 && dp[idx][visited]+sum >= answer) return dp[idx][visited]+sum;

	int result = 1e9;
	for (int i = 1; i < table.size(); i++) {
		if (visited&(1<<i) || !table[idx][i]) continue;
		int r = dfs(d+1, i, sum+table[idx][i], visited+(1<<i));
		if (r > 0) result = min(r, result);
	}

	if (result == 1e9) return dp[idx][visited] = -1;
	dp[idx][visited] = result-sum;
	return result;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N;
	cin >> N;

	dp = vector<vector<int>>(N, vector<int>(1<<N, 1e9));
	table = vector<vector<int>>(N, vector<int>(N, 0));
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> table[r][c];

	int answer = dfs(1, 0, 0, 1);

	cout << answer << "\n";

	return 0;
}