#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  cin >> test;
  for (int t = 0; t < test; t++) {
    int n, m;
    cin >> n >> m;
    
    vector<vector<long long>> map(m, vector<long long>(n+1, 0));

    for (int i = 0; i <= 11; i++) {
      if (i == 10) continue;
      if (map[i%m][1] < i) map[i%m][1] = i;
    }

    for (int i = 1; i < n; i++) {
      for (int a = 0; a < m; a++) {
        if (map[a][i] == 0) continue;
        for (int b = 0; b <= 9; b++) {
          long long nNum = map[a][i]*10+b;
          if (map[nNum%m][i+1] < nNum) map[nNum%m][i+1] = nNum;
        }
        long long nNum2 = map[a][i]*100+11;
        if (map[nNum2%m][i+1] < nNum2) map[nNum2%m][i+1] = nNum2;
      }
    }
    cout << map[0][n] << "\n";
  }
  return 0;
}
