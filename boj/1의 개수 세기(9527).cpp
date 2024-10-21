#include <iostream>
#include <algorithm>

using namespace std;

long long countOne(long long num) {
	int n = 0;
	long long result = 0;
	while ((1ll<<n) <= num) {
		long long div = 1ll<<(n+1);
		result += num/div*(1ll<<n);
		if (num%div > (1ll<<n)-1) result += num%div - ((1ll<<n)-1);
		n++;
	}
	return result;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	long long A, B;
	cin >> A >> B;

	cout << countOne(B) - countOne(A-1) << "\n";

	return 0;
}