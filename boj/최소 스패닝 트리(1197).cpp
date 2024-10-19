#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> visited;
vector<vector<vector<int>>> path;

struct cmp {
	bool operator() (vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

priority_queue<vector<int>, vector<vector<int>>, cmp> q;

long long dfs(int v, int d, int sum) {
	if ( d == visited.size()-1) {
		return sum;
	}

	for (vector<int> p: path[v])
		if (!visited[p[0]]) q.push(p);

	while (q.size() && visited[q.top()[0]])
		q.pop();

	if (q.empty()) return 2e10;

	vector<int> top = q.top();
	q.pop();
	visited[top[0]] = 1;
	return dfs(top[0], d+1, sum+top[1]);
}



int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int V, E;
	cin >> V >> E;

	path = vector<vector<vector<int>>>(V+1);
	visited = vector<int>(V+1, 0);

	for (int i = 0; i < E; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		path[s].push_back({e, c});
		path[e].push_back({s, c});
	}

	visited[1] = 1;
	long long answer = dfs(1, 1, 0);

	cout << answer << "\n";
	return 0;
}