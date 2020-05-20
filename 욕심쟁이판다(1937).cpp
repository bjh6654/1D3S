#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> table, depth;
int p[] = {-1, 0, 1, 0};
int q[] = {0, 1, 0, -1};

struct loc {
	int r, c, a;
};

bool comp(loc a, loc b) {
	return a.a > b.a;
}

bool isRange(int r, int c) {
	if ( r >= 0 && r < N && c >= 0 && c < N )
		return true;
	return false;
}

void dfs(int count, int r, int c, int s_r, int s_c) {
	depth[s_r][s_c] = max(count+depth[r][c]-1, depth[s_r][s_c]);
	if ( depth[r][c] > 1 )
		return;
	
	for ( int i = 0; i < 4; i++ ) {
		int R = r + p[i];
		int C = c + q[i];
		if ( isRange(R, C) && table[r][c] < table[R][C] )
			dfs(count+1, R, C, s_r, s_c);
	}
}

int main() {
	cin >> N;
	table.assign(N, vector<int>(N, 0));
	depth.assign(N, vector<int>(N, 1));
	
	vector<loc> arr;
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < N; c++ ) {
			cin >> table[r][c];
			arr.push_back({r, c, table[r][c]});
		}
	
	sort(arr.begin(), arr.end(), comp);
	for ( loc l : arr )
		dfs(1, l.r, l.c, l.r, l.c);
			
	int result = 0;
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < N; c++ )
			result = max(result, depth[r][c]);
	cout << result;
}
