#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> makePattern(int N, int r, int c) {
	vector<vector<char>> table(N, vector<char>(N, ' '));
		
	if ( r == 1 && c == 1 )
		return table;
	if ( N == 1 ) {
		table[0][0] = '*';
		return table;
	}
	
	for ( int r = 0; r < 3; r++ ) {
		for ( int c = 0; c < 3; c++ ) {
			vector<vector<char>> t = makePattern(N/3, r, c);
			int R = r*(N/3), C = c*(N/3);
			for ( int i = 0; i < t.size(); i++ )
				for ( int j = 0; j < t.size(); j++ )
					table[R+i][C+j] = t[i][j];
		}
	}
	return table;
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);
	
	int N;
	cin >> N;
	
	vector<vector<char>> result = makePattern(N, 0, 0);
	for ( int r = 0; r < N; r++ ) {
		for ( int c = 0; c < N; c++ )
			cout << result[r][c];
		cout << "\n";
	}
}
