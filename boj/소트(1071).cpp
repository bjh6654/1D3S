#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void insertValue(vector<int>& result, vector<int>& num) {
  for (int i = 0; i < num.size(); i++) {
    int n = num[i];
    if (!result.size() || result.back()+1 != n) {
      result.push_back(n);
      num.erase(num.begin()+i);
      return;
    }
  }
  int n = num.back();
  for (int i = result.size()-1; i >= 0; i--) {
    if (n == result[i]-1) continue;
    if (i >= 1 && n == result[i-1]+1) continue;
    result.insert(result.begin()+i, n);
    num.pop_back();
    return;
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<int> num(n);
  for (int i = 0; i < n; i++)
    cin >> num[i];

  sort(num.begin(), num.end());

  vector<int> result;

  while (num.size()) {
    insertValue(result, num);
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i];
    if (i != result.size()-1) cout << " ";
  }

  return 0;
}