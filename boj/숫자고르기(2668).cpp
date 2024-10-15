#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
vector<int> cycle;

bool dfs(int i, int init) {
	if (num[i] == init) return true;
	if (!cycle[num[i]]) {
		cycle[num[i]] = 1;
		if (!dfs(num[i], init)) {
			cycle[num[i]] = 0;
			return false;
		}
		return true;
	}
	return false;
}

int main() {
	int N;
	cin >> N;

	num = vector<int>(N+1);
	cycle = vector<int>(N+1, 0);
	for (int i = 1; i <= N; i++) cin >> num[i];

	for (int i = 1; i <= N; i++) {
		if (!cycle[i]) {
			cycle[i] = 1;
			if (!dfs(i, i)) cycle[i] = 0;
		}
	}

	vector<int> result;
	for (int i = 1; i <= N; i++) {
		if (cycle[i]) result.push_back(i);
	}

	cout << result.size() << "\n";
	for (int i: result)
		cout << i << "\n";

	return 0;
}
