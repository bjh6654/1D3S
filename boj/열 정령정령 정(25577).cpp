#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N;
	cin >> N;

	map<int, int> m;

	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		m.insert({num[i], i});
	}

	vector<int> sorted = num;
	sort(sorted.begin(), sorted.end());

	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (num[i] == sorted[i]) continue;
		m[num[i]] = m[sorted[i]];
		iter_swap(num.begin()+i, num.begin()+m[sorted[i]]);
		answer++;
	}

	cout << answer << "\n";

	return 0;
}