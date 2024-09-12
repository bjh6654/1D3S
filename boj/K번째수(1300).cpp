#include <iostream>

using namespace std;

int main() {
	long long N, K;
	cin >> N >> K;
	
	long long mini = 1, maxi = min(1000000000LL, N*N), mid = 1;
	
	while ( mini < maxi ) {
		mid = (maxi + mini) / 2;
		
		int sum = 0, limit = min(N, mid);
		for ( int i = 1; i <= limit; i++ )
			sum += min(mid/i, N);
		
		if ( sum >= K ) {
			maxi = mid;
		} else {
			mini = mid + 1;
		}
	}
	cout << mini;
}
