#include <iostream>

using namespace std;

long long num[101][10];

bool isRange(int n) {
	if ( n >= 0 && n <= 9 )
		return true;
	return false;
}

int main() {
	int N;
	cin >> N;
	
	fill(num[1]+1, num[1]+10, 1);
	for ( int i = 2; i <= N; i++ ) {
		for ( int n = 0; n <= 9; n++ ) {
			if ( isRange(n-1) )
				num[i][n-1] = (num[i][n-1] + num[i-1][n]) % 1000000000;
			if ( isRange(n+1) )
				num[i][n+1] = (num[i][n+1] + num[i-1][n]) % 1000000000;
		}
	}
	
	long long sum = 0;
	for ( int i = 0; i <= 9; i++ )
		sum = (sum + num[N][i]) % 1000000000;
	cout << sum;
}
