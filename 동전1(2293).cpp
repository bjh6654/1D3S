#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result[10001];

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int N, K;
	cin >> N >> K;
	
	vector<int> coin(N);
	for ( int i = 0; i < N; i++ )
		cin >> coin[i];

	sort(coin.begin(), coin.end());
	
	for ( int cost : coin ) {
		if ( cost > K )
			break;
		result[cost]++;
		for ( int n = cost+1; n <= K; n++ )
			result[n] += result[n-cost];
	}
	cout << result[K];
}
