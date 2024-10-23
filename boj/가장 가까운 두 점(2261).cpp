#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> points;

int getDistance(vector<int> a, vector<int> b) {
	return (b[1]-a[1])*(b[1]-a[1]) + (b[0]-a[0])*(b[0]-a[0]);
}

int pow2(int a, int b) {
	return (a-b)*(a-b);
}

int divideSearch(int s, int e, int d) {
	if (s+1 == e) return getDistance(points[s], points[e]);
	if (s >= e) return d;

	int mid = s + (e-s)/2;
	d = min(divideSearch(s, mid, d), d);
	d = min(divideSearch(mid+1, e, d), d);

	vector<vector<int>> p;
	for (int i = s; i <= e; i++)
		if (pow2(points[i][0], points[mid][0]) < d) {
			p.push_back({points[i][1], points[i][0]});
		} else if (points[i][0] > points[mid][0]) break;
	sort(p.begin(), p.end());
	for (int a = 0; a < p.size(); a++)
		for (int b = a+1; b < p.size(); b++) {
			if (pow2(p[a][0], p[b][0]) >= d) break;
			int dist = getDistance(p[a], p[b]);
			if (dist < d) d = dist;
		}
	
	return d;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	long long N;
	cin >> N;

	points = vector<vector<int>>(N);
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		points[i] = {x, y};
	}

	sort(points.begin(), points.end());

	int d = divideSearch(0, N-1, 1e9);

	cout << d << "\n";

	return 0;
}