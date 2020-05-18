#include <iostream>
#include <vector>

using namespace std;

struct water {
	int i, h;
};

vector<vector<int>> path;
vector<int> height;
vector<int> max_height;

bool isReach(int current, int h, int K) {
	if ( current == K )
		return true;
	for ( int i = 0; i < path[current].size(); i++ ) {
		int dest = path[current][i];
		if ( h >= height[dest] ) {
			int bound = height[dest] + (h - height[dest])/2;
			if ( bound > max_height[dest] ) {
				max_height[dest] = bound;
				if ( isReach(dest, bound, K) )
					return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K;
	cin >> N >> K;
	
	height.resize(N+1);
	max_height.resize(N+1);
	for ( int i = 1; i <= N; i++ )
		cin >> height[i];
	copy(height.begin(), height.end(), max_height.begin());
	max_height[K] = 0;
	
	path.resize(N+1);
	for ( int i = 0; i < N-1; i++ ) {
		int u, v;
		cin >> u >> v;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	
	for ( int i = 1; i <= N; i++ ) {
		if ( i != K && isReach(i, height[i], K) ) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}
