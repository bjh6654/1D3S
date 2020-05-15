#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<bool>> visit(31, vector<bool>(80005, false));
vector<int> iron(31, 0);
vector<bool> result(80005, false);

void dfs(int count, int idx, int sum) {
	visit[count][sum] = true;
	result[sum] = true;
	
	for ( int i = idx+1; i < N; i++ ) {
		if ( !visit[count+1][sum+iron[i]] )
			dfs(count+1, i, sum+iron[i]);
		if ( !visit[count+1][sum-iron[i]] )
			dfs(count+1, i, sum-iron[i]);
		if ( !visit[count+1][sum] )
			dfs(count+1, i, sum);
	}
}

int main() {
	cin >> N;
	
	for ( int i = 0; i < N; i++ )
		cin >> iron[i];

	dfs(0, -1, 40000);
	
	cin >> M;
	for ( int i = 0; i < M; i++ ) {
		int target;
		cin >> target;
		if ( result[target+40000] )
			cout << "Y ";
		else
			cout << "N ";
	}
	
}
