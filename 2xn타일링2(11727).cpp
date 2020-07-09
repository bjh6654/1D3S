#include <iostream>

using namespace std;

int result[1001];

int main() {
	int N;
	cin >> N;
	
	result[0] = 0;
	result[1] = 1;
	result[2] = 3;
	for ( int i = 3; i <= N; i++ ) {
		result[i] = (result[i-1] + result[i-2] * 2) % 10007;
	}
	cout << result[N];
}
