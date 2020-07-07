#include <iostream>

using namespace std;

int len[1000001]; 

int main() {
	int N;
	cin >> N;
	
	len[0] = 0;
	len[1] = 1;
	len[2] = 2;
	for ( int i = 3; i <= N; i++ )
		len[i] = (len[i-2] + len[i-1]) % 15746;
	cout << len[N];
}
