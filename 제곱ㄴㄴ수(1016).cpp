#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	long long min, max;
	cin >> min >> max;
	
	vector<long long> mul;
	
	for ( long long i = 2; i <= sqrt(max); i++ )
		mul.push_back(i*i);
	
	long long size = max-min+1;
	vector<bool> nono(1000001, true);
	
	for ( long long p : mul ) {
		long long remain = min % p;
		if ( remain != 0 )
			remain = p - remain;
		while ( remain < size ) {
			nono[remain] = false;
			remain += p;
		}
	}
	
	int sum = 0;
	for ( int i = 0; i < size; i++ )
		sum += nono[i];
	cout << sum;
}
