#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int map[100][100];
int p[4] = {-1, 0, 1, 0};
int q[4] = {0, 1, 0, -1};

struct loc {
	int r, c;
};

bool isRange(int r, int c) {
	if ( r >= 0 && r < N && c >= 0 && c < N )
		return true;
	return false;
}

void area(int a, int r, int c) {
	queue<loc> que;
	que.push({r, c});

	vector<vector<bool>> visit(N, vector<bool>(N, false));
	
	while ( !que.empty() ) {
		map[que.front().r][que.front().c] = a;
		
		for ( int i = 0; i < 4; i++ ) {
			int R = que.front().r + p[i];
			int C = que.front().c + q[i];
			if ( isRange(R, C) && map[R][C] == 1 && !visit[R][C] ) {
				visit[R][C] = true;
				que.push({R, C});
			}
		}
		que.pop();
	}
}

int bridge(int a, queue<loc> que, vector<vector<bool>> visit, int step) {
	queue<loc> tmp;
	
	while ( !que.empty() ) {
		if ( map[que.front().r][que.front().c] != a && map[que.front().r][que.front().c] != 0 )
			return step-1;
		
		for ( int i = 0; i < 4; i++ ) {
			int R = que.front().r + p[i];
			int C = que.front().c + q[i];
			if ( isRange(R, C) && map[R][C] != a && !visit[R][C] ) {
				visit[R][C] = true;
				tmp.push({R, C});
			}
		}
		que.pop();
	}
	
	return bridge(a, tmp, visit, step+1);
}

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	cin >> N;
	
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < N; c++ )
			cin >> map[r][c];
	
	int a = 2;
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < N; c++ )
			if ( map[r][c] == 1 )
				area(a++, r, c);
	
	int result = 2e9;
	for ( int i = 2; i < a; i++ ) {
		queue<loc> que;
		for ( int r = 0; r < N; r++ )
			for ( int c = 0; c < N; c++ )	
				if ( map[r][c] == i )
					que.push({r, c});
		
		vector<vector<bool>> visit(N, vector<bool>(N, false));
		result = min(result, bridge(i, que, visit, 0));
	}
	cout << result;
}
