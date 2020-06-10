#include <iostream>
#include <algorithm>

using namespace std;

int inc[40000], size;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int N, num;
	cin >> N;

	for ( int i = 0; i < N; i++ ) {
		cin >> num;
		
		if ( inc[size] < num )
			inc[++size] = num;
		else
			*lower_bound(inc, inc+size, num) = num;
	}
	cout << size;
}
