#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp (vector<int> a, vector<int> b) {
	return a[1] > b[1];
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> jewel(N, vector<int>(2));
	for (int i = 0; i < N; i++)
		cin >> jewel[i][0] >> jewel[i][1];

	sort(jewel.begin(), jewel.end());

	vector<int> bag(K);
	for (int i = 0; i < K; i++)
		cin >> bag[i];
	
	sort(bag.begin(), bag.end());

	priority_queue<int> q;

	int idx = 0;
	long long answer = 0;
	for (int b: bag) {
		while (idx < jewel.size() && jewel[idx][0] <= b) {
			q.push(jewel[idx][1]);
			idx++;
		}

		if (q.size()) {
			answer += q.top();
			q.pop();
		}
	}

	cout << answer << "\n";

	return 0;
}