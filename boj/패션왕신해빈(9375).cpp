#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	int T, N;
	string category, name;
	cin >> T;
	
	while ( T-- ) {
		cin >> N;
		unordered_map<string, int> map;
		for ( int i = 0; i < N; i++ ) {
			cin >> name >> category;
			if ( !map.count(category) )
				map[category] = 1;
			else
				map[category]++;
		}
		
		int result = 1;
		for ( pair<string, int> p : map ) {
			result *= p.second + 1;
		}
		cout << result - 1 << "\n";
	}
}
