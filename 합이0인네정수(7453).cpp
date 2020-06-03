#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int N;
	cin >> N;
	
	vector<vector<int>> table(N, vector<int>(4));
	for ( int r = 0; r < N; r++ )
		for ( int c = 0; c < 4; c++ )
			cin >> table[r][c];
			
	vector<int> num1, num2;
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < N; j++ ) {
			num1.push_back(table[i][0]+table[j][1]);
			num2.push_back(table[i][2]+table[j][3]);
		}
	}
	
	sort(num2.begin(), num2.end());
	long long count = 0;
	for ( int n : num1 ) {
		vector<int>::iterator iter = lower_bound(num2.begin(), num2.end(), -n);
		vector<int>::iterator iter2 = lower_bound(num2.begin(), num2.end(), -n+1);
		count += iter2 - iter;
	}
	cout << count;
}
