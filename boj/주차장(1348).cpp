#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> map;
vector<vector<vector<int>>> connMap;
vector<vector<int>> visited;
vector<vector<int>> direct({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});
vector<vector<vector<int>>> connect(101);

bool isRange(int r, int c) {
	if (r < 0 || r > visited.size()-1 || c < 0 || c > visited[0].size()-1 ) return false;
	return true;
}

void bfs(queue<vector<int>> q, int step, int car) {
	queue<vector<int>> next;
	while (q.size()) {
		vector<int> cur = q.front();
		q.pop();
		if (map[cur[0]][cur[1]] == 'P') connect[car].push_back({cur[0], cur[1], step});

		for (vector<int> d: direct) {
			int R = cur[0]+d[0], C = cur[1]+d[1];
			if (!isRange(R, C) || map[R][C] == 'X' || visited[R][C]) continue;
			visited[R][C] = 1;
			next.push({R, C});
		}
	}
	if (next.size()) bfs(next, step+1, car);
}

bool dfs(int car, int check) {
	for (vector<int> p: connect[car]) {
		if (p[2] > check) continue;
		int r = p[0], c = p[1];
		if (visited[r][c]) continue;
		visited[r][c] = 1;
		if (connMap[r][c][0] == -1 || dfs(connMap[r][c][0], check)) {
			connMap[r][c] = {car, p[2]};
			return true;
		}
	}
	return false;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int R, C;
	cin >> R >> C;
	map = vector<string>(R);
	for (int r = 0; r < R; r++) cin >> map[r];

	int car = 0;
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			if (map[r][c] == 'C') {
				queue<vector<int>> q;
				q.push({r, c});

				visited = vector<vector<int>>(R, vector<int>(C, 0));
				visited[r][c] = 1;
				bfs(q, 0, car);

				car++;
			}

	if (!car) {
		cout << 0 << "\n";
		return 0;
	}

	int answer = -1;
	int low = 0, high = 5000;
	while (low < high) {
		int check = low + (high-low)/2;

		connMap = vector<vector<vector<int>>>(R, vector<vector<int>>(C, vector<int>({-1, 0})));
		int matched = 0;
		for (int i = 0; i < car; i++) {
			visited = vector<vector<int>>(R, vector<int>(C, 0));
			if (dfs(i, check)) matched++;
		}
		if (matched == car) {
			high = check;
			answer = check;
		} else {
			low = check+1;
		}
	}

	cout << answer << "\n";

	return 0;
}
