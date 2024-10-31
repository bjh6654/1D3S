#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MAX = 1e9+7;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  long long n = 1;
  vector<long long> num(N), count(N);
  for (int i = 0; i < N; i++) {
    cin >> num[i];
    count[i] = n;
    n = (n*2) % MAX;
  }

  sort(num.begin(), num.end());

  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += (num[i]*(count[i]-count[N-1-i]+MAX)) % MAX;
    if (sum > 0) sum %= MAX;
  }

  cout << sum << "\n";

	return 0;
}