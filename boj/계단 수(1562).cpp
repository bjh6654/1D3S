#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<vector<long long>>> dp(101, vector<vector<long long>>(10, vector<long long>(1024, 0)));
	
	for (int r = 1; r <= N; r++)
		for (int c = 0; c < 10; c++) {
			if (r == 1) {
				if (c == 0) continue;
				dp[r][c][1<<c] = 1;
			}
			for (int v = 0; v < 1024; v++) {
				int t = v|(1<<c);
				if (c+1 < 10) dp[r][c][t] += dp[r-1][c+1][v];
				if (c-1 >= 0) dp[r][c][t] += dp[r-1][c-1][v];
				dp[r][c][t] %= (int)1e9;
			}
		}
	
	long long sum = 0;
	for (int i = 0; i < 10; i++)
		sum += dp[N][i][1023];
	sum %= (int)1e9;

	cout << sum << "\n";

	return 0;
}