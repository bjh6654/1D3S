#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct loc {
	int r, c;
};

vector<vector<int>> person(21, vector<int>(21, 0));

int area1(int x, int y, int d1, int d2, int N) {
	queue<loc> que;
	que.push({1, 1});
	vector<vector<bool>> visit(N+1, vector<bool>(N+1, false));
	visit[1][1] = true;
	int sum = person[1][1];
	while ( !que.empty() ) {
		int r = que.front().r;
		int c = que.front().c;
		que.pop();
		
		if ( r+1 < x+d1 && r+1+c < x+y && !visit[r+1][c] ) {
			que.push({r+1, c});
			sum += person[r+1][c];
			visit[r+1][c] = true;
		}
		if ( c+1 <= y && r+c+1 < x+y && !visit[r][c+1] ) {
			que.push({r, c+1});
			sum += person[r][c+1];
			visit[r][c+1] = true;
		}
	}
	return sum;
}

int area2(int x, int y, int d1, int d2, int N) {
	queue<loc> que;
	que.push({1, N});
	vector<vector<bool>> visit(N+1, vector<bool>(N+1, false));
	visit[1][N] = true;
	int sum = person[1][N];
	while ( !que.empty() ) {
		int r = que.front().r;
		int c = que.front().c;
		que.pop();
		
		if ( r+1 <= x+d2 && abs(y-c)+x > r+1 && !visit[r+1][c] ) {
			que.push({r+1, c});
			sum += person[r+1][c];
			visit[r+1][c] = true;
		}
		if ( c-1 > y && abs(y-(c-1))+x > r && !visit[r][c-1] ) {
			que.push({r, c-1});
			sum += person[r][c-1];
			visit[r][c-1] = true;
		}
	}
	return sum;
}

int area3(int x, int y, int d1, int d2, int N) {
	queue<loc> que;
	que.push({N, 1});
	vector<vector<bool>> visit(N+1, vector<bool>(N+1, false));
	visit[N][1] = true;
	int sum = person[N][1];
	while ( !que.empty() ) {
		int r = que.front().r;
		int c = que.front().c;
		que.pop();
		
		if ( r-1 >= x+d1 && c-(y-d1)+(x+d1) < r-1 && !visit[r-1][c] ) {
			que.push({r-1, c});
			sum += person[r-1][c];
			visit[r-1][c] = true;
		}
		if ( c+1 < y-d1+d2 && (c+1)-(y-d1)+(x+d1) < r && !visit[r][c+1] ) {
			que.push({r, c+1});
			sum += person[r][c+1];
			visit[r][c+1] = true;
		}
	}
	return sum;
}

int area4(int x, int y, int d1, int d2, int N) {
	queue<loc> que;
	que.push({N, N});
	vector<vector<bool>> visit(N+1, vector<bool>(N+1, false));
	visit[N][N] = true;
	int sum = person[N][N];
	while ( !que.empty() ) {
		int r = que.front().r;
		int c = que.front().c;
		que.pop();
		
		if ( r-1 > x+d2 && r-1+c > x+y+d2*2 && !visit[r-1][c] ) {
			que.push({r-1, c});
			sum += person[r-1][c];
			visit[r-1][c] = true;
		}
		if ( c-1 >= y-d1+d2 && r+c-1 > x+y+d2*2 && !visit[r][c-1] ) {
			que.push({r, c-1});
			sum += person[r][c-1];
			visit[r][c-1] = true;
		}
	}
	return sum;
}

int main() {
	int N;
	cin >> N;
	
	int sum = 0;
	for ( int r = 1; r <= N; r++ )
		for ( int c = 1; c <= N; c++ ) {
			cin >> person[r][c];
			sum += person[r][c];
		}
	
	int result = 2e9;
	for ( int x = 1; x <= N; x++ ) {
		for ( int y = 1; y <= N; y++ ) {
			for ( int d1 = 1; 1 <= y-d1; d1++ ) {
				for ( int d2 = 1; y+d2 <= N && x+d1+d2 <= N; d2++ ) {
					int a1 = area1(x, y, d1, d2, N);
					int a2 = area2(x, y, d1, d2, N);
					int a3 = area3(x, y, d1, d2, N);
					int a4 = area4(x, y, d1, d2, N);
					int a5 = sum - (a1+a2+a3+a4);
					int maximum = max(a1, max(a2, max(a3, max(a4, a5))));
					int minimum = min(a1, min(a2, min(a3, min(a4, a5))));
					result = min(result, maximum - minimum);
				}
			}
		}
	}
	
	cout << result << endl;
}
