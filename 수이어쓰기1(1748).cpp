#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	long long sum = 0;
	int loc = 10, len = 1;
	for ( int i = 1; i <= n; i++ ) {
		if ( i / loc == 0 ) {
			sum += len;
		} else {
			loc *= 10;
			len += 1;
			sum += len;
		}
	}
	cout << sum;
}
