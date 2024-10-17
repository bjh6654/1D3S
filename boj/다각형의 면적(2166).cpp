#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<long long>> points(N, vector<long long>(2));
	for (int i = 0; i < N; i++)
		cin >> points[i][0] >> points[i][1];

	long long a1 = 0, a2 = 0, sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += points[i-1][0]*points[i%N][1] - points[i-1][1]*points[i%N][0];
	}

	cout << fixed;
	cout.precision(1);
	cout << abs((double)sum)/2 << "\n";

	return 0;
}