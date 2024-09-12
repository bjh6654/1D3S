#include <iostream>

using namespace std;

int map[16][16];

int main() {
	int R, C, K;
	cin >> R >> C >> K;
	
	map[1][1] = 1;
	if ( !K ) {
		for ( int r = 1; r <= R; r++ )
			for ( int c = 1; c <= C; c++ )
				if ( r != 1 || c != 1 )
					map[r][c] = map[r-1][c] + map[r][c-1];
		cout << map[R][C];
	} else {
		int tr = (K-1) / C + 1;
		int tc = (K-1) % C + 1;
		 
		for ( int r = 1; r <= tr; r++ )
			for ( int c = 1; c <= tc; c++ )
				if ( r != 1 || c != 1 )
					map[r][c] = map[r-1][c] + map[r][c-1];
		for ( int r = tr; r <= R; r++ )
			for ( int c = tc; c <= C; c++ )
				if ( r != 1 || c != 1 )
					map[r][c] = map[r-1][c] + map[r][c-1];
		cout << map[R][C];
	}
}
