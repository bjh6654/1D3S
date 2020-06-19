#include <iostream>
#include <queue>

using namespace std;

int N, M, H, count;
int map[101][101][101];
int p[6] = {-1, 0, 1, 0, 0, 0};
int q[6] = {0, 1, 0, -1, 0, 0};
int o[6] = {0, 0, 0, 0, -1, 1};

struct loc {
	int r, c, h, d;
};

bool isRange(int r, int c, int h) {
	if ( r >= 0 && r < M && c >= 0 && c < N && h >= 0 && h < H )
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	cin >> N >> M >> H;
	
	queue<loc> que;
	for ( int h = 0; h < H; h++ )
		for ( int r = 0; r < M; r++ )
			for ( int c = 0; c < N; c++ ) {
				cin >> map[r][c][h];
				if ( map[r][c][h] == 1 )
					que.push({r, c, h, 0});
				else if ( map[r][c][h] == 0 )
					count++;
			}

	if ( !count ) {
		cout << 0;
	} else {
		while ( !que.empty() ) {
			loc tmp = que.front();	que.pop();
			for ( int i = 0; i < 6; i++ ) {
				int r = tmp.r + p[i];
				int c = tmp.c + q[i];
				int h = tmp.h + o[i];
				
				if ( isRange(r, c, h) && !map[r][c][h] ) {
					map[r][c][h] = 1;
					que.push({r, c, h, tmp.d+1});
					if ( --count == 0 ) {
						cout << tmp.d+1;
						return 0;
					}
				}
			}
		}
		cout << -1;
	}
}
