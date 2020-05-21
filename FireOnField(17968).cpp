#include <iostream>
#include <vector>

using namespace std;

bool check(int n, int i, vector<int> arr) {
	for ( int k = 1; k <= i/2; k++ )
		if ( n - arr[i-k] == arr[i-k] - arr[i-2*k] )
			return false;
	return true;
}

int main() {
	int N;
	cin >> N;
	vector<int> arr(1001);
	arr[0] = 1;
	arr[1] = 1;
	for ( int i = 2; i <= N; i++ ) {
		int n = 1;
		while ( !check(n, i, arr) ) {
			n++;
		}
		arr[i] = n;
	}
	
	cout << arr[N];
}
