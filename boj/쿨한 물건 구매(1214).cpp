#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	long long D, P, Q;
	cin >> D >> P >> Q;

	if (D % P == 0 || D % Q == 0) {
		cout << D << "\n";
		return 0;
	}

	if (P < Q) swap(P, Q);

	long long cP = min(D/P + 1, Q);

	long long result = (D/P + 1)*P;
	while (cP >= 0) {
		long long g = D-(cP*P);
		if (g >= 0) {
			if (g % Q == 0) {
				cout << D << "\n";
				return 0;
			}
			result = min((g/Q + 1)*Q+(cP*P), result);
		}
		cP--;
	}

	cout << result << "\n";

	return 0;
}