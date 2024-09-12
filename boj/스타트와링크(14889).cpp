#include <iostream>
#include <vector>

using namespace std;

int N, result = 2e9;
vector<vector<int>> ab;
vector<int> arr1, arr2;

int sumOfmember(vector<int> arr) {
	int sum = 0;
	for ( int i = 0; i < arr.size(); i++ )
		for ( int j = i+1; j < arr.size(); j++ )
			sum += ab[arr[i]][arr[j]];
	return sum;
}

void dfs(int idx, int c1, int c2) {
	if ( idx == N ) {
		int sum1 = sumOfmember(arr1);
		int sum2 = sumOfmember(arr2);
		result = result < abs(sum1-sum2) ? result : abs(sum1-sum2);
		return;
	}
	if ( c1 < N/2 ) {
		arr1[c1] = idx;
		dfs(idx+1, c1+1, c2);	
	}
	if ( c2 < N/2 ) {
		arr2[c2] = idx;
		dfs(idx+1, c1, c2+1);
	}
}

int main() {
	cin >> N;
	
	ab.assign(N, vector<int>(N, 0));
	arr1.resize(N/2);
	arr2.resize(N/2);
	
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < N; c++ )
			cin >> ab[r][c];
	
	for ( int r = 0; r < N; r++ )
		for ( int c = r; c < N; c++ )
			ab[r][c] += ab[c][r];
	
	dfs(0, 0, 0);
	cout << result;
}
