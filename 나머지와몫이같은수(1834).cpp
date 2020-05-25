#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	long long sum = 0;
	for ( long long i = 1; i < N; i++ )
		sum += (N+1)*i;
		
	cout << sum;
}
