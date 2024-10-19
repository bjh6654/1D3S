#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N;
	cin >> N;

	vector<long long> num(N);
	for (int i = 0; i < N; i++) cin >> num[i];

	int left = 0, right = N-1;

	long long diff = 2e10;
	vector<long long> result;
	while (left < right) {
		if (abs(num[left] + num[right]) < diff) {
			diff = abs(num[left] + num[right]);
			result = {num[left], num[right]};
		}
		if (num[left] + num[right] < 0) left++;
		else if (num[left] + num[right] > 0) right--;
		else {
			cout << num[left] << " " << num[right] << "\n";
			return 0;
		}
	}

	cout << result[0] << " " << result[1] << "\n";


	return 0;
}