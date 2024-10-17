#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int K;
	cin >> K;

	vector<vector<int>> line(6, vector<int>(2));
	for (int i = 0; i < 6; i++)
		cin >> line[i][0] >> line[i][1];

	for (int i = 0; i < 6; i++)
		line.push_back(line[i]);

	int width = 0, height = 0;
	for (vector<int> l: line) {
		if (l[0] == 1 || l[0] == 2) width = max(width, l[1]);
		else height = max(height, l[1]);
	}

	int area = width*height;
	for (int i = 0; i+3 < line.size(); i++) {
		if (line[i][0] == line[i+2][0] && line[i+1][0] == line[i+3][0]) {
			area -= line[i+1][1]*line[i+2][1];
			break;
		}
	}

	cout << area*K << "\n";

	return 0;
}