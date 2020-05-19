#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	
	int N;
	long long num;
	cin >> N;
	
	long long small_div = 2e9, big_div = 0;
	for ( int i = 0; i < N; i++ ) {
		cin >> num;
		small_div = small_div > num ? num : small_div;
		big_div = big_div < num ? num : big_div;
	}
	
	cout << small_div * big_div;
}
