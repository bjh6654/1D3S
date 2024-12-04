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

  vector<int> num(N);
  for (int i = 0; i < N; i++) cin >> num[i];

  vector<int> result(N, 1e9+1);
  for (int n: num) {
    int left = 0, right = N-1;
    while (left < right) {
      int check = left + (right - left)/2;
      if (result[check] >= n) right = check;
      else left = check + 1;
    }
    result[left] = n;
  }

  int count = 0;
  for (int n: result) if (n <= 1e9) count++;

  cout << count << "\n";

	return 0;
}