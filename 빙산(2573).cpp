#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> table;

int p[] = {-1, 0, 1, 0};
int q[] = {0, 1, 0, -1};

bool isRange(int r, int c) {
	if ( r >= 0 && r < N && c >= 0 && c < M )
		return true;
	return false;
}

pair<int, int> find_ice(vector<vector<int>> table) {
	for ( int r = 1; r < N-1; r++ )
		for ( int c = 1; c < M-1; c++ )
			if ( table[r][c] != 0 )
				return make_pair(r, c);
	return make_pair(-1, -1);
}

bool isDivided(int none_zero, vector<vector<int>> table) {
	queue<pair<int, int>> que;
	
	pair<int, int> ice = find_ice(table);
	if ( ice.first == -1 ) {
		cout << "0";
		exit(0);
	}
	que.push(ice);
	
	int count = -1;
	while ( !que.empty() ) {
		int r = que.front().first;
		int c = que.front().second;
		que.pop();
		count += 1;
		
		for ( int i = 0; i < 4; i++ ) {
			int R = r + p[i], C = c + q[i];
			if ( isRange(R, C) && table[R][C] != 0 ) {
				table[R][C] = 0;
				que.push(make_pair(R, C));
			}
		}
	}

	if ( none_zero == count )
		return false;
	return true;
}

int bfs(int time, int none_zero, vector<vector<int>> table) {
	if ( isDivided(none_zero, table) )
		return time;
	
	vector<vector<int>> tmp(N, vector<int>(M, 0));
	
	int count = 0;
	for ( int r = 0; r < N; r++ ) {
		for ( int c = 0; c < M; c++ ) {
			if ( table[r][c] != 0 ) {
				int reduce = 0;
				for ( int i = 0; i < 4; i++ ) {
					int R = r + p[i], C = c + q[i];
					if ( isRange(R, C) && table[R][C] == 0 )
						reduce += 1;
				}
				tmp[r][c] = max(0, table[r][c]-reduce);
				if ( tmp[r][c] != 0 )
					count += 1;
			}
		}
	}
	
	copy(tmp.begin(), tmp.end(), table.begin());
	
	return bfs(time+1, count, table);
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	cin >> N >> M;
	table.assign(N, vector<int>(M, 0));
	
	int none_zero = 0;
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < M; c++ ) {
			cin >> table[r][c];
			if ( table[r][c] != 0 )
				none_zero += 1;
		}
		
	cout << bfs(0, none_zero, table);	
}
