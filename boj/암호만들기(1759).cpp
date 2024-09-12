#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char c[15];

void dfs(int idx, int count, string str, int mo, int ja) {
	if ( count == L ) {
		if ( mo != 0 && ja >= 2 )
			cout << str << "\n";
		return;
	}
	
	for ( int i = idx+1; i < C; i++ ) {
		if ( c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u' )
			dfs(i, count+1, str+c[i], mo+1, ja);
		else
			dfs(i, count+1, str+c[i], mo, ja+1);
	
	}
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	cin >> L >> C;
	
	for ( int i = 0; i < C; i++ )
		cin >> c[i];
	
	sort(c, c+C);
	
	dfs(-1, 0, "", 0, 0);
}
