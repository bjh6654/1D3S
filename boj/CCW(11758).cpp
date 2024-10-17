#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solve(vector<vector<int>> p) {
	if (p[0][0] == p[1][0]) {
		if (p[0][0] == p[2][0]) return 0;
		if (p[2][0] < p[0][0]) return 1*(p[0][1] < p[1][1] ? 1 : -1);
		return -1*(p[0][1] < p[1][1] ? 1 : -1);
	}
	long long incline = p[1][1]-p[0][1];
	long long value = incline*(p[2][0]-p[0][0])-(p[2][1]-p[0][1])*(p[1][0]-p[0][0]);

	if (value == 0) return 0;
	if (value > 0) return -1;
	return 1;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	vector<vector<int>> p(3, vector<int>(2));
	for (int i = 0; i < 3; i++)
		cin >> p[i][0] >> p[i][1];

	cout << solve(p) << "\n";

	return 0;
}