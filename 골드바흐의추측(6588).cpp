#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> prime(1000001, true);
vector<int> plist;

void getPrime() {
	for ( int i = 2; i <= 1000000; i++ ) {
		if ( prime[i] ) {
			plist.push_back(i);
			int k = i*2;
			while ( k <= 1000000 ) {
				prime[k] = false;
				k += i;
			}
		}
	}
}

void printResult(int N) {
	for ( int i = 0; i < plist.size(); i++ ) {
		if ( N-plist[i] < plist[i] )
			break;
		if ( prime[N-plist[i]] ) {
			cout << N << " = " << plist[i] << " + " << N-plist[i] << "\n";
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong.\n";
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	getPrime();
	
	while ( true ) {
		cin >> N;
		if ( !N )
			return 0;
		printResult(N);
	}
}
