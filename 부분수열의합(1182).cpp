#include <iostream>
#include <vector>

using namespace std;

int dfs(int idx, vector<int> num, int target, int sum, bool select) {
	if ( idx == num.size()-1 ) {
		if ( select && sum == target )
			return 1;
		return 0;
	}
	return dfs(idx+1, num, target, sum, select | false) + dfs(idx+1, num, target, sum+num[idx+1], true);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, S;
	cin >> N >> S;
	vector<int> numlist(N);
	
	for ( int i = 0; i < N; i++ )
		cin >> numlist[i];
		
	cout << dfs(-1, numlist, S, 0, false);
}
