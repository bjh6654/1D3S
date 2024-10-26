#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> first;

bool isLeft(vector<long long> a, vector<long long> b, vector<long long> c) {
	if (a[0] == b[0]) {
		if (a[0] == c[0]) return false;
		if (c[0] < a[0]) return a[1] < b[1];
		return a[1] >= b[1];
	}
	long long incline = b[1]-a[1];
	long long value = incline*(c[0]-a[0])-(c[1]-a[1])*(b[0]-a[0]);

	if (value >= 0) return false;
	return true;
}

double getDegree(vector<long long> a, vector<long long> b) {
  if (b[0] == a[0]) {
    if (b[1] == a[1]) return -1e9;
    return 1e9;
  }
  return (b[1]-a[1])/(double)(b[0]-a[0]);
}

bool cmp(vector<long long> a, vector<long long> b) {
  return getDegree(first, a) < getDegree(first, b);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  long long x, y;
  vector<vector<long long>> point(N);
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    point[i] = {x, y};
  }

  sort(point.begin(), point.end());

  first = point[0];

  stable_sort(point.begin(), point.end(), cmp);

  int i = 2;
  vector<vector<long long>> answer({point[0], point[1]});

  while (i < N) {
    vector<long long> a = answer[answer.size()-2];
    vector<long long> b = answer[answer.size()-1];
    if (a[0] == b[0] && a[1] == b[1]) {
      answer.pop_back();
      if (answer.size() < 2) answer.push_back(point[i++]);
      continue;
    }
    if (isLeft(a, b, point[i])) {
      answer.push_back(point[i++]);
    } else {
      answer.pop_back();
      if (answer.size() < 2) answer.push_back(point[i++]);
    }
  }

  cout << answer.size() << "\n";

	return 0;
}