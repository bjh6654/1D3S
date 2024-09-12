#include <iostream>

using namespace std;

int value[100001];

int main() {
	int N;
	cin >> N;
	
	fill(value, value+100001, 1e9);
	int v = 1;
	while ( v*v <= N ) {
		value[v*v] = 1;
		v += 1;
	}
	for ( int i = 1; i <= N; i++ ) {
		int c = 1;
		while ( i + c*c <= N ) {
			value[i+c*c] = min(value[i+c*c], value[i]+1);
			c += 1;
		}
	}
	cout << value[N];
}
