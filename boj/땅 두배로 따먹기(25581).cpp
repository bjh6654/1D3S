#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> card;
vector<int> odd, even;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N;
	cin >> N;

	card = vector<int>(N);
	for (int i = 0; i < N; i++)
		cin >> card[i];

	sort(card.begin(), card.end(), greater<>());

  if (N <= 3) {
    cout << (card[0]+card[1])*2 << "\n";
    return 0;
  }

  odd = vector<int>(N, 0), even = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
    if (i >= 1) {
      odd[i] = odd[i-1];
      even[i] = even[i-1];
    }
    if (i%2) odd[i] += card[i];
    else even[i] += card[i];
  }

  vector<vector<int>> dp(N, vector<int>(2, -1));
  for (int r = 0; r+1 < N; r++) {
    for (int c = 0; c+1 < N; c++) {
      if (abs(r-c) <= 1) continue;
      if (r < c && (r%2 || c%2)) continue;
      if (c < r && (!(c%2) || !(r%2))) continue;
      int san = 0, hyun = 0;
      if (r < c) {
        san = (even[r]+card[r+1])*2 + (odd[c]-odd[r+1]) + (even[N-1]-even[c]);
        hyun = (odd[r] + even[c]-even[r] + card[c+1])*2 + (odd[N-1]-odd[c+1]);
      } else {
        san = (even[c] + odd[r]-odd[c] + card[r+1])*2 + (even[N-1]-even[r+1]);
        hyun = (odd[c]+card[c+1])*2 + (even[r]-even[c+1]) + (odd[N-1]-odd[r]);       
      }
      if (r < c) {
        if (dp[r][1] < hyun) {
          dp[r] = {san, hyun};
        } else if (dp[r][1] == hyun && dp[r][0] > san) {
          dp[r][0] = san;
        }
      } else {
        if (dp[c][0] < san) {
          dp[c] = {san, hyun};
        } else if (dp[c][0] == san && dp[c][1] > hyun) {
          dp[c][1] = hyun;
        }
      }
    }
  }

  for (int i = N-2; i >= 0; i--) {
    if (i%2) {
      if (dp[i][1] < dp[i+1][1]) {
        dp[i] = dp[i+1];
      } else if (dp[i][1] == dp[i+1][1]) {
        dp[i][0] = min(dp[i][0], dp[i+1][0]);
      }
    } else {
      if (dp[i][0] < dp[i+1][0]) {
        dp[i] = dp[i+1];
      } else if (dp[i][0] == dp[i+1][0]) {
        dp[i][1] = min(dp[i][1], dp[i+1][1]);
      }
    }
  }

  cout << dp[0][0] << "\n";
	return 0;
}