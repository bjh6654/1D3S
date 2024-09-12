#include <iostream>

using namespace std;

int V, E, s, e, c;
int map[401][401];

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	cin >> V >> E;
	
	fill(&map[0][0], &map[400][401], 1e7);
	
	for ( int i = 0; i < E; i++ ) {
		cin >> s >> e >> c;
		map[s][e] = c;
	}

	for ( int p = 1; p <= V; p++ )
		for ( int r = 1; r <= V; r++ )
			for ( int c = 1; c <= V; c++ )
				map[r][c] = min(map[r][c], map[r][p] + map[p][c]);	

	int result = 1e7;
	for ( int r = 1; r <= V; r++ )
		result = min(result, map[r][r]);
	
	if ( result == 1e7 )
		cout << -1;
	else
		cout << result;
}
