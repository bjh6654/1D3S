#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, K;
  cin >> N >> M >> K;

  vector<vector<int>> dp(M+1, vector<int>(K, 0));
  vector<vector<int>> f(K, vector<int>(3));
  
  for (int i = 0; i < K; i++)
    cin >> f[i][0] >> f[i][1] >> f[i][2];

  for (int i = 0; i < K; i++) {
    int init = f[i][0];
    int term = f[i][1];
    int price = f[i][2];
    
    for (int d = init; d <= M; d++) {
      dp[d][i] = (d-init)/term*price+price;
    }
  }

  vector<int> maxPrice(M+1, 0);
  for (int i = 1; i <= M; i++) {
    for (int a = 0; a < K; a++) maxPrice[i] = max(maxPrice[i], dp[i][a]);

    for (int j = 1; j <= i/2; j++) maxPrice[i] = max(maxPrice[i], maxPrice[i-j]+maxPrice[j]);
  }

  cout << maxPrice[M]*N << "\n";

	return 0;
}