#include <iostream>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	
	int result = 2e9;
	for ( int i = 0; i < b.length(); i++ ) {
		if ( i + a.length() <= b.length() ) {
			int diff = 0;
			for ( int ac = 0; ac < a.length(); ac++ )
				if ( a[ac] != b[ac+i] )
					diff++;
			result = min(result, diff);
		} else
			break;
	}
	cout << result;
}
