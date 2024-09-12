#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int p[] = { -1, 0, 1, 0 };
int q[] = { 0, 1, 0, -1 };

bool isRange(int r, int c) {
	if ( r >= 0 && r < N && c >= 0 && c < N )
		return true;
	return false;
}

int area(int anum, int sr, int sc, vector<vector<int>> &table) {
	queue<pair<int, int>> que;
	que.push(make_pair(sr, sc));
	
	int count = 0;
	while ( !que.empty() ) {
		int R = que.front().first;
		int C = que.front().second;
		que.pop();
		
		if ( table[R][C] == 1 ) {
			table[R][C] = anum;
			count++;
		} else 
			continue;
		
		for ( int i = 0; i < 4; i++ ) {
			int r = R + p[i], c = C + q[i];
			if ( isRange(r, c) && table[r][c] == 1 )
				que.push(make_pair(r, c));
		}
	}
	return count;
}

int main() {
	cin >> N;
	
	vector<vector<int>> table(N, vector<int>(N));
	
	for ( int r = 0; r < N; r++ ) {
		string line;
		cin >> line;
		for ( int c = 0; c < N; c++ )
			table[r][c] = line[c]-'0';
	}
	
	int anum = 2;
	vector<int> size;
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < N; c++ )
			if ( table[r][c] == 1 )
				size.push_back(area(anum++, r, c, table));
	sort(size.begin(), size.end());
	
	cout << size.size() << "\n";
	for ( int s : size )
		cout << s << "\n";
}
