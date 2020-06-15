#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	int N, n;
	cin >> N;
	
	vector<vector<int>> adj(N);
	
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < N; c++ ) {
			cin >> n;
			if ( n )
				adj[r].push_back(c);
		}
	
	vector<vector<int>> result;
	for ( int r = 0; r < N; r++ ) {
		queue<int> que;
		vector<int> avail(N, 0);
		for ( int d : adj[r] ) {
			que.push(d);
			avail[d] = 1;
		}
		
		
		while ( !que.empty() ) {
			int idx = que.front();	que.pop();
			
			for ( int d : adj[idx] ) {
				if ( !avail[d] ) {
					que.push(d);
					avail[d] = 1;
				}
			}
		}
		result.push_back(avail);
	}
	
	for ( int r = 0; r < N; r++ ) {
		for ( int c = 0; c < N; c++ )
			cout << result[r][c] << " ";
		cout << "\n";
	}
}
