#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	bool flag = false;
	vector<vector<int>> table(N, vector<int>(M, 0));
	for ( int r = 0; r < N; r++ ) {
		string row;
		cin >> row;
		for ( int c = 0; c < M; c++ )
			table[r][c] = row[c]-'0';
	}
	
	int size = 0;
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < M; c++ )
			if ( table[r][c] ) {
				if ( r && c )
					table[r][c] = min(table[r-1][c-1], min(table[r-1][c], table[r][c-1])) + 1;				
				size = max(size, table[r][c]);
			}

	cout << size * size;
}
