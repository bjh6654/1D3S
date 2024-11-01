#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int w, n;
  cin >> w >> n;

  vector<int> num(n);
  for (int i = 0; i < n; i++)
    cin >> num[i];

  sort(num.begin(), num.end());

  unordered_map<int, pair<int, int>> pre, post;

  for (int i = 0; i < n; i++)
    for (int k = i+1; k < n; k++) {
      if (num[i]+num[k] >= w) break;
      // if (pre.find(num[i]+num[k]) != pre.end()) continue;
      pre[num[i]+num[k]] = {i, k};
    }

  for (auto it = pre.begin(); it != pre.end(); it++) {
    int sum = it->first;
    if (sum >= w) continue;
    auto itt = pre.find(w-sum);
    if (itt == pre.end()) continue;
    if (itt->second.first == it->second.first || itt->second.first == it->second.second || itt->second.second == it->second.first || itt->second.second == it->second.second) continue;
    cout << "YES" << "\n";
    return 0;
  }

  cout << "NO" << "\n";

	return 0;
}