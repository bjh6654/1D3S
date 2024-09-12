#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, x1, y1, x2, y2;
int map[101][101];
int p[4] = {-1, 0, 1, 0};
int q[4] = {0, 1, 0, -1};

bool isRange(int r, int c) {
	if ( r >= 0 && r < N && c >= 0 && c < M )
		return true;
	return false;
}

int bfs(int r, int c) {
	map[r][c] = 2;
	queue<pair<int, int>> que;
	que.push({r, c});
	
	int size = 0;
	while ( !que.empty() ) {
		for ( int i = 0; i < 4; i++ ) {
			int R = que.front().first + p[i], C = que.front().second + q[i];

			if ( isRange(R, C) && !map[R][C] ) {
				map[R][C] = 2;
				que.push({R, C});
			}
		}
		que.pop();
		size++;
	}
	return size;
}

int main() {
	cin >> N >> M >> K;
	
	for ( int i = 0; i < K; i++ ) {
		cin >> x1 >> y1 >> x2 >> y2;
		for ( int r = y1; r < y2; r++ )
			for ( int c = x1; c < x2; c++ )
				map[r][c] = 1;
	}
	
	vector<int> s;
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < M; c++ )
			if ( !map[r][c] )
				s.push_back(bfs(r, c));
	
	sort(s.begin(), s.end());
	
	cout << s.size() << "\n";
	for ( int a : s )
		cout << a << " ";
}
