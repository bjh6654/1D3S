#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int N, num;
	cin >> N;
	
	int sum = 0, result = -1e9;
	for ( int i = 0; i < N; i++ ) {
		cin >> num;
		sum += num;
		result = max(result, sum);
		if ( sum < 0 )
			sum = 0;
	}
	cout << result;
}
