#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> path;
vector<vector<int>> dp;
vector<bool> visited;

int dfs(int v, int selected) {
	if (dp[v][selected] != -1) {
		return dp[v][selected];
	}

	int result = 0;
	for (int p: path[v]) {
		if (visited[p]) continue;
		visited[p] = 1;
		int add = dfs(p, 1);
		if (selected) add = min(dfs(p, 0), add);
		result += add;
		visited[p] = 0;
	}
	return dp[v][selected] = result + selected;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N;
	cin >> N;

	path = vector<vector<int>>(N+1);
	visited = vector<bool>(N+1, false);
	int s, e;
	for (int i = 0; i < N-1; i++) {
		cin >> s >> e;
		path[s].push_back(e);
		path[e].push_back(s);
	}

	dp = vector<vector<int>>(N+1, vector<int>(2, -1));
	visited[1] = 1;
	int a1 = dfs(1, 0);
	int a2 = dfs(1, 1);

	cout << min(a1, a2) << "\n";
	

	return 0;
}