#include <iostream>

using namespace std;

int main() {
	string str;
	cin >> str;
	
	int len = str.length();
	int s = 0, d = min(10, len);
	while ( s < len ) {
		cout << str.substr(s, d) << "\n";
		s += d;
		d = min(10, len-d);
	}
}
