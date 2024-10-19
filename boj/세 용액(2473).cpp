#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N;
	cin >> N;

	vector<long long> num(N);
	for (int i = 0; i < N; i++) cin >> num[i];

	sort(num.begin(), num.end());

	long long diff = 2e10;
	vector<long long> result;
	for (int i = 0; i < N-2; i++) {
		int left = i+1, right = N-1;
		while (left < right) {
			if (abs(num[i] + num[left] + num[right]) < diff) {
				diff = abs(num[i] + num[left] + num[right]);
				result = {num[i], num[left], num[right]};
			}
			if (num[i] + num[left] + num[right] < 0) left++;
			else if (num[i] + num[left] + num[right] > 0) right--;
			else {
				cout << num[i] << " " << num[left] << " " << num[right] << "\n";
				return 0;
			}
		}
	}

	cout << result[0] << " " << result[1] << " " << result[2] << "\n";

	return 0;
}