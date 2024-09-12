#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> visit;
vector<int> num, sum;
vector<vector<int>> dp;

int solve(int n, int m) {
	if ( m == 0 )
		return 0;
	if ( n <= 0 )
		return -2e9;
	
	if ( visit[n][m] )
		return dp[n][m];
	visit[n][m] = true;
	
	dp[n][m] = solve(n-1, m);
	for ( int i = 1; i <= n; i++ )
		dp[n][m] = max(solve(i-2, m-1) + sum[n] - sum[i-1], dp[n][m]);
	return dp[n][m]; 
}

int main() {
	int N, M;
	cin >> N >> M;
	
	num.assign(N+1, 0);
	sum.assign(N+1, 0);
	visit.assign(N+1, vector<bool>(N/2+1, false));
	
	for ( int i = 1; i <= N; i++ ) {
		cin >> num[i];
		sum[i] = sum[i-1] + num[i];
	}
		
	dp.assign(N+1, vector<int>(N/2+1, 0));
	
	cout << solve(N, M);
}
