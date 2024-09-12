#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> dp;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int N;
	cin >> N;
	
	vector<int> num(N);
	for ( int i = 0; i < N; i++ )
		cin >> num[i];
	
	dp.assign(N, vector<long long>(21, 0));
	
	dp[0][num[0]] = 1;
	for ( int r = 1; r < N-1; r++ ) {
		int n = num[r];
		for ( int i = 0; i <= 20; i++ ) {
			if ( dp[r-1][i] != 0 ) {
				if ( i + n <= 20 )
					dp[r][n+i] += dp[r-1][i];
				if ( i - n >= 0 )
					dp[r][i-n] += dp[r-1][i];
			}
		}
	}
	
	cout << dp[N-2][num.back()];
}
