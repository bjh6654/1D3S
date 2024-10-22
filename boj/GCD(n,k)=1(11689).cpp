#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	long long N;
	cin >> N;

	vector<long long> divide;
	for (int i = 1; i <= sqrt(N); i++) {
		if (N%i == 0) {
			divide.push_back(i);
			if (N/i != i) divide.push_back(N/i);
		}
	}

	sort(divide.begin(), divide.end());

	long long answer = N;
	for (long long i: divide) {
		if (i == 1 || N%i) continue;
		answer -= answer/i;
		while (N%i == 0) N /= i;
	}
	if (N > 1) answer -= answer/N;

	cout << answer << "\n";

	return 0;
}