#include <iostream>
#include <unordered_map>

using namespace std;

int p[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int q[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

bool isRange(string loc) {
	if ( 'A' <= loc[0] && 'H' >= loc[0] && '1' <= loc[1] && '8' >= loc[1] )
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	unordered_map<string, int> map;
	map["T"] = 0;
	map["R"] = 1;
	map["B"] = 2;
	map["L"] = 3;
	map["RT"] = 4;
	map["RB"] = 5;
	map["LB"] = 6;
	map["LT"] = 7;
	
	string king, stone, inst;
	int N;
	
	cin >> king >> stone >> N;

	for ( int i = 0; i < N; i++ ) {
		cin >> inst;
		string tmp = king;
		tmp[0] = tmp[0] + q[map[inst]];
		tmp[1] = tmp[1] + p[map[inst]];
		
		if ( isRange(tmp) ) {
			if ( tmp == stone ) {
				string stmp = stone;
				stmp[0] = stmp[0] + q[map[inst]];
				stmp[1] = stmp[1] + p[map[inst]];
				
				if ( isRange(stmp) ) {
					stone = stmp;
					king = tmp;
				}
			} else {
				king = tmp;
			}
		}
	}
	cout << king << "\n" << stone;
}
