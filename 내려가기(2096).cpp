#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int N, num;
	cin >> N;
	
	vector<pair<int, int>> table(3, {0, 0});
	for ( int r = 1; r <= N; r++ ) {
		vector<pair<int ,int>> row(3, {0, 2e9});
		for ( int c = 0; c < 3; c++ ) {
			cin >> num;
			for ( int i = -1; i <= 1; i++ ) {
				if ( c + i >= 0 && c + i < 3 ) {
					row[c].first = max(row[c].first, num+table[c+i].first);
					row[c].second = min(row[c].second, num+table[c+i].second);
				}
			}
		}
		table = row;
	}
	cout << max(table[0].first, max(table[1].first, table[2].first)) << " " << min(table[0].second, min(table[1].second, table[2].second));
}
