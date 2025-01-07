#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, div;
  cin >> N;

  vector<int> leaf(N);
  for (int i = 0; i < N; i++) cin >> leaf[i];
  for (int i = 0; i < N; i++) {
    cin >> div;
    leaf[i] = (int)ceil((double)leaf[i]/div);
  }

  sort(leaf.rbegin(), leaf.rend());

  long long left = 1, right = 1e9;
  while (left < right) {
    long long check = left + (right-left)/2;

    long long sum = 0;
    for (int i = 0; i < N; i++) {
      if (leaf[i] <= check) break;
      sum += leaf[i]-check;
      if (sum > check) break;
    }

    if (sum <= check) right = check;
    else left = check+1;
  }

  cout << left << "\n";

	return 0;
}