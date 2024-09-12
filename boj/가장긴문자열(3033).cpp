#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long MOD = 100003;

int mod(long long n){
    if ( n >= 0 )
		return n % MOD;
    return ((-n/MOD+1)*MOD + n) % MOD;
}

bool checkSame(int i, int idx, int len, string str) {
	for ( int a = 0; a < len; a++ ) {
		if ( str[i+a] != str[idx+a] )
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	int N;
	cin >> N;
	
	string str;
	cin >> str;
	
	int minlen = 0, maxlen = N, len;
	
	while ( minlen < maxlen ) {
		bool flag = false;
		len = (minlen + maxlen) / 2;
		long long hash = 0;
		vector<vector<int>> h(MOD);
		
		long long p = 1;
		
		for ( int i = 0; i < len; i++ ) {
			hash = mod(hash + p*(str[i]-'0'));
			p = mod(p*2);
		}
		p /= 2;
		
		h[hash].push_back(0);
		for ( int i = 1; i+len-1 < N; i++ ) {
			hash = mod((hash - (str[i-1]-'0'))/2 + p*(str[i+len-1]-'0'));
			if ( !h[hash].empty() ) {
				for ( int idx : h[hash] ) {
					if ( checkSame(i, idx, len, str) ) {
						flag = true;
						break;
					}
				}
			} else {
				h[hash].push_back(i);
			}
			if ( flag )
				break;
		}
		if ( flag )
			minlen = len+1;
		else
			maxlen = len;
	}
	cout << len;
}

