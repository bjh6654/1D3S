#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> table;

bool isDup(int mid, int C) {
	unordered_map<string, int> m;
	for ( int r = 0; r < C; r++ ) {
		string sub = table[r].substr(mid);
		if ( !m.count(sub) )
			m[sub];
		else
			return true;
	}
	return false;
}

int main() {
	int R, C;
	cin >> R >> C;
	
	table.resize(C);
	
	for ( int r = 0; r < R; r++ ) {
		string line;
		cin >> line;
		for ( int c = 0; c < C; c++ )
			table[c].push_back(line[c]);
	}
	
	int start = 0, end = R, mid;
	while ( start < end ) {
		mid = (start+end) / 2;
		
		if ( isDup(mid, C) )
			end = mid;
		else
			start = mid+1;
	}
	cout << start-1;
}
