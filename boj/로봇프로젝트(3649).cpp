#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<long long> weight, long long X) {
	sort(weight.begin(), weight.end());
	
	int start = 0, end = weight.size()-1;
	while ( start < end ) {
		long long sum = weight[start] + weight[end];
		if ( sum > X )
			end--;
		else if ( sum < X  )
			start++;
		else {
			cout << "yes " << weight[start] << " " << weight[end] << "\n";
			return;
		}
	}
	cout << "danger\n";
}

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	while ( true ) {
		long long X, N;
		cin >> X >> N;
		if ( cin.eof() )
			break;
		X *= 1e7;
	
		vector<long long> weight(N);
		for ( int i = 0; i < N; i++ )
			cin >> weight[i];
		
		solve(weight, X);
	}
}
