#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

bool comp(string a, string b) {
	if ( a.length() == b.length() )
		return a < b;
	return a.length() < b.length();
}

bool check(vector<string> contact) {
	for ( int i = 0; i < contact.size()-1; i++ ) {
		int len = contact[i].length();
		string sub = contact[i+1].substr(0, len);
		if ( contact[i] == sub )
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0), cin.tie(0);
	
	cin >> T;
	
	for ( int t = 0; t < T; t++ ) {
		cin >> N;
		vector<string> contact(N);
		for ( int i = 0; i < N; i++ )
			cin >> contact[i];
		
		sort(contact.begin(), contact.end());
		if ( check(contact) )
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}
