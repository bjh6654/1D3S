#include <iostream>
#include <vector>

using namespace std;

bool isRange(int r, int c, int N, int M) {
	if ( r < 0 || r > N-1 || c < 0 || c > M-1 ) return false;
	return true;
}

int main() {

	int N, M;
	cin >> N >> M;

	int answer = 0;
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(4, 0)));

	vector<vector<int>> d({{-1, -1}, {-1, 1}});
	string line;
	for (int r = 0; r < N; r++) {
		cin >> line;
		for (int c = 0; c < M; c++) {
			if (line[c] == '1') {
				answer = 1;
				dp[r][c][0] = 1;
				dp[r][c][1] = 1;
				for (int i = 0; i <= 1; i++) {
					if (isRange(r-1, c+d[i][1], N, M))
						dp[r][c][i] = dp[r-1][c+d[i][1]][i] + 1;
				}
			}
		}
	}

	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++) {
			if (r < ((answer+1)*2-1-1) || min(dp[r][c][0], dp[r][c][1]) <= answer) continue;
			for (int i = min(dp[r][c][0], dp[r][c][1]); i > answer; i--) {
				if (dp[r-i+1][c-i+1][1] >= i && dp[r-i+1][c+i-1][0] >= i) {
					answer = i;
					break;
				}
			}
		}
	
	cout << answer << "\n";

	return 0;
}
