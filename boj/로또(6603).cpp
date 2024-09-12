#include <iostream>
#include <vector>

using namespace std;

void printComb(vector<int> num, vector<int> result, int idx, int count) {
	if ( count == 6 ) {
		for ( int i = 0; i < 6; i++ )
			cout << result[i] << " ";
		cout << "\n";
		return;
	}
	for ( int i = idx+1; i < num.size(); i++ ) {
		result[count] = num[i];
		printComb(num, result, i, count+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while ( true ) {
		int k;
		cin >> k;
		if ( k == 0 )
			return 0;
		
		vector<int> numlist(k, 0);
		vector<int> result(6, 0);		
		for ( int i = 0; i < k; i++ )
			cin >> numlist[i];
		
		printComb(numlist, result, -1, 0);
		cout << "\n";
	}
}
