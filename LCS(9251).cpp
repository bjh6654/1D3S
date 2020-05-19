#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);		cout.tie(0);
	
	string s1, s2;
	cin >> s1 >> s2;
	s1 = "*" + s1;
	s2 = "*" + s2;
	
	int row = s1.length();
	int col = s2.length();
	
	vector<vector<int>> table(row, vector<int>(col, 0));
	for ( int r = 1; r < row; r++ ) {
		for ( int c = 1; c < col; c++ ) {
			int val = 0;
			if ( s1[r] == s2[c] )
				val = 1;
			table[r][c] = max(table[r-1][c-1] + val, max(table[r-1][c], table[r][c-1]));
		}
	}
	cout << table[row-1][col-1];
}
