#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vertex {
	int idx, group;
};

bool search(int V, vector<vector<int>> adj) {
	vector<int> group(V+1, 2);
	
	for ( int start = 1; start <= V; start++ ) {
		if ( group[start] == 2 ) {
			queue<vertex> que;
		
			que.push({start, 0});
			group[start] = 0;
			
			while ( !que.empty() ) {
				int idx = que.front().idx, g = que.front().group;
				que.pop();
				
				for ( int d : adj[idx] ) {
					if ( group[d] == 2 ) {
						group[d] = !g;
						que.push({d, !g});
					} else if ( group[d] == g ) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	int K;
	cin >> K;
	
	while ( K-- ) {
		int V, E, s, e;
		cin >> V >> E;
		
		vector<vector<int>> adj(V+1);
		for ( int i = 0; i < E; i++ ) {
			cin >> s >> e;
			
			adj[s].push_back(e);
			adj[e].push_back(s);
		}
		
		if ( search(V, adj) )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
