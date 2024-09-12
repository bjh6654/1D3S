#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct data {
	int dest, time;
};

vector<vector<data>> table(1001);
vector<int> min_time(1001, 2e9);

void return_time(int start, int ctime) {
	for ( int i = 0; i < table[start].size(); i++ ) {
		int dest = table[start][i].dest;
		int time = ctime + table[start][i].time;
		if ( min_time[dest] > time ) {
			min_time[dest] = time;
			return_time(dest, time);
		}
	}
}

struct comp {
	bool operator() (data a, data b) {
		return a.time > b.time;
	}
};

int shortest(int start, int dest) {
	priority_queue<data, vector<data>, comp> que;
	que.push({start, 0});
	
	vector<int> minarr(1001, 2e9);
	
	while ( !que.empty() ) {
		data top = que.top();	que.pop();
		if ( top.dest == dest )
			return top.time;
		for ( data d : table[top.dest] ) {
			if ( minarr[d.dest] > d.time + top.time ) {
				minarr[d.dest] = d.time + top.time;
				que.push({d.dest, d.time + top.time});
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	int N, M, X, s, e, t;
	cin >> N >> M >> X;
	
	for ( int i = 0; i < M; i++ ) {
		cin >> s >> e >> t;
		table[s].push_back({e, t});
	}
	
	return_time(X, 0);
		
	int result = 0;
	for ( int i = 1; i <= N; i++ ) {
		if ( i != X )
			result = max(result, min_time[i] + shortest(i, X));
	}
	cout << result;
}
