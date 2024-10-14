#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> direct({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});

bool isRange(int r, int c) {
	if ( r < 0 || r > 9 || c < 0 || c > 9) return false;
	return true;
}

void turnSwitch(vector<vector<int>>& table, int r, int c) {
	table[r][c] = !table[r][c];
	for (vector<int> d: direct) {
		int R = r + d[0], C = c + d[1];
		if (isRange(R, C)) table[R][C] = !table[R][C];
	}
}

bool checkTable(vector<vector<int>> table) {
	for (int r = 0; r < table.size(); r++)
		for (int c = 0; c < table[0].size(); c++)
			if (table[r][c]) return false;
	return true;
}

int dfs(int d, int sum) {
	if (d == 10) {
		vector<vector<int>> table = map;
		for (int r = 1; r < 10; r++)
			for (int c = 0; c < 10; c++)
				if (table[r-1][c] == 1) {
					turnSwitch(table, r, c);
					sum += 1;
				}
		if (checkTable(table)) return sum;
		return 1e9;
	}

	int result = 1e9;
	result = min(dfs(d+1, sum), result);
	turnSwitch(map, 0, d);
	result = min(dfs(d+1, sum+1), result);
	turnSwitch(map, 0, d);
	return result;
}

int main() {
	map = vector<vector<int>>(10, vector<int>(10, 0));
	
	string line;
	for (int r = 0; r < 10; r++) {
		cin >> line;
		for (int c = 0; c < 10; c++)
			if (line[c] == 'O') map[r][c] = 1;
	}

	int answer = dfs(0, 0);
	if (answer == 1e9) answer = -1;
	cout << answer << "\n";

	return 0;
}
