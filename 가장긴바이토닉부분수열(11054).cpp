#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	int N;
	cin >> N;
	
	vector<int> num(N);
	for ( int i = 0; i < N; i++ )
		cin >> num[i];
	
	vector<int> expand, result(N, -1);
	for ( int i = 0; i < N; i++ ) {
		if ( expand.empty() || expand.back() < num[i] ) {
			expand.push_back(num[i]);
		} else {
			vector<int>::iterator iter = lower_bound(expand.begin(), expand.end(), num[i]);
			*iter = num[i];
		}
		result[i] += expand.size();
	}
	
	expand.clear();
	for ( int i = N-1; i >= 0; i-- ) {
		if ( expand.empty() || expand.back() < num[i] ) {
			expand.push_back(num[i]);
		} else {
			vector<int>::iterator iter = lower_bound(expand.begin(), expand.end(), num[i]);
			*iter = num[i];
		}
		result[i] += expand.size();
	}
	
	cout << *max_element(result.begin(), result.end());
}
