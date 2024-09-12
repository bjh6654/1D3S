#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, result = 2e9, anum = 2;
int p[] = { -1, 0, 1, 0 };
int q[] = { 0, 1, 0, -1 };

struct bridge {
	int area1, area2, len;
};

vector<vector<int>> table;
vector<vector<int>> len;
vector<bridge> b;
vector<vector<int>> adj(10);

bool isRange(int r, int c) {
	if ( r >= 0 && r < N && c >= 0 && c < M )
		return true;
	return false;
}

void area(int anum, int sr, int sc, vector<vector<int>> &table) {
	queue<pair<int, int>> que;
	que.push(make_pair(sr, sc));
	
	while ( !que.empty() ) {
		int R = que.front().first;
		int C = que.front().second;
		que.pop();
		
		if ( table[R][C] == 1 )
			table[R][C] = anum;
		else
			continue;
		
		for ( int i = 0; i < 4; i++ ) {
			int r = R + p[i], c = C + q[i];
			if ( isRange(r, c) && table[r][c] == 1 )
				que.push(make_pair(r, c));
		}
	}
}

void check(int r, int c, int i) {
	int m = 1;
	while ( isRange(r+p[i]*m, c+q[i]*m) && table[r+p[i]*m][c+q[i]*m] == 0 ) {
		m++;
	}

	int R = r+p[i]*m, C = c+q[i]*m;
	if ( m > 2 && isRange(R, C) && table[R][C] != table[r][c] ) {
		int area1 = table[r][c], area2 = table[R][C];
		int length = min(min(len[area1][area2], len[area2][area1]), m-1);
		len[area1][area2] = length;
		len[area2][area1] = length;
	}
}

bool bfs() {
	vector<bool> v(10, false);
	
	queue<int> que;
	que.push(2);
	
	while ( !que.empty() ) {
		int a = que.front();	que.pop();
		
		for ( int e : adj[a] ) {
			if ( !v[e] ) {
				v[e] = true;
				que.push(e);
			}
		}
	}
	
	for ( int i = 2; i < anum; i++ )
		if ( !v[i] )
			return false;
	return true;
}

void dfs(int idx, int sum) {
	if ( bfs() )
		result = min(result, sum);
	
	for ( int i = idx+1; i < b.size(); i++ ) {
		int s = b[i].area1, e = b[i].area2;
		adj[s].push_back(e);
		adj[e].push_back(s);
		dfs(i, sum+b[i].len);
		adj[s].pop_back();
		adj[e].pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);

	cin >> N >> M;
	
	table.resize(N, vector<int>(M));
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < M; c++ )
			cin >> table[r][c];
	

	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < M; c++ )
			if ( table[r][c] == 1 )
				area(anum++, r, c, table);
	
	len.resize(anum, vector<int>(anum, 999));
	
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < M; c++ )
			if ( table[r][c] != 0 )		
				for ( int i = 0; i < 4; i++ )
					check(r, c, i);

	for ( int r = 2; r < anum; r++ )
		for ( int c = r+1; c < anum; c++ )
			if ( len[r][c] != 999 )
				b.push_back({r, c, len[r][c]});
				
	dfs(-1, 0);
	
	if ( result == 2e9 )
		cout << -1;
	else
		cout << result;
}
