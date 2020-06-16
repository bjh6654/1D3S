#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[101][101], result[101][101];
int p[4] = {-1, 0, 1, 0};
int q[4] = {0, 1, 0, -1};

struct node {
	int r, c, b;
};

bool isRange(int r, int c) {
	if ( r > 0 && r < N-1 && c > 0 && c < M-1 )
		return true;
	return false;
}

void bfs(queue<node> que) {
	fill(&result[0][0], &result[101][101], 2e9);
	
	while ( !que.empty() ) {
		int R = que.front().r;
		int C = que.front().c;
		int b = que.front().b;
		que.pop();
		
		for ( int i = 0; i < 4; i++ ) {
			int r = R + p[i], c = C + q[i];
			if ( isRange(r, c) && b + map[r][c] < result[r][c] ) {
				result[r][c] = b + map[r][c];
				que.push({r, c, result[r][c]});
			}
		}
	}
}

int main() {
	cin >> N >> M;
	
	for ( int r = 0; r <  N; r++ )
		for ( int c = 0; c < M; c++ )
			cin >> map[r][c];
	
	queue<node> que;
	for ( int r = 0; r <  N; r++ )
		for ( int c = 0; c < M; c++ )
			if ( r == 0 || r == N-1 || c == 0 || c == M-1 )
				que.push({r, c, 0});
	
	bfs(que); 
	
	int day = 0, count = 0;
	for ( int r = 1; r < N-1; r++ )
		for ( int c = 1; c < M-1; c++ )
			if ( result[r][c] > day ) {
				day = result[r][c];
				count = 1;
			} else if ( day && map[r][c] && result[r][c] == day ) {
				count++;
			}
	
	cout << day << "\n" << count;
}
