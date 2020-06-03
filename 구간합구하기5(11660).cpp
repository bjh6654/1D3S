#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	int N, M, sr, sc, er, ec;
	cin >> N >> M;
	
	vector<vector<int>> table(N+1, vector<int>(N+1, 0));
	for ( int r = 1; r <= N; r++ )
		for ( int c = 1; c <= N; c++ ) {
			cin >> table[r][c];
			table[r][c] += table[r][c-1];
		}
	
	for ( int i = 0; i < M; i++ ) {
		cin >> sr >> sc >> er >> ec;
		int sum = 0;
		for ( int r = sr; r <= er; r++ ) {
			sum += table[r][ec] - table[r][sc-1];
		}
		cout << sum << "\n";
	}
}
