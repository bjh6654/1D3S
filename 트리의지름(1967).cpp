#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct path {
	int e, c;
};

vector<path> adj[10001];
int result, N;

int dfs(int idx, int length) {
	vector<int> len;
	for ( path p : adj[idx] )
		len.push_back(dfs(p.e, p.c));
	
	if ( len.size() >= 2 ) {
		sort(len.begin(), len.end(), greater<int>());
		result = max(result, len[0] + len[1]);
	}
	
	if ( !len.empty() )
		length += len[0];
	
	return length;
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
		
	cin >> N;
		
	for ( int i = 0; i < N-1; i++ ) {
		int s, e, c;
		cin >> s >> e >> c;
		adj[s].push_back({e, c});
	}
	
	int line = dfs(1, 0);
	cout << max(result, line);
}
