#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N, S;
	cin >> N >> S;

	vector<int> num(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		num[i] += num[i-1];
	}

	if (num[N] < S) {
		cout << 0 << "\n";
		return 0;
	}

	int s = 0, e = 0;
	int result = N;

	while (s <= N && e <= N) {
		if (num[e]-num[s] < S) e++;
		else {
			result = min(e-s, result);
			s++;
		}
	}

	cout << result << "\n";

	return 0;
}