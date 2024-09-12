#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int N, num;
	cin >> N;
	
	vector<int> p;
	for ( int i = 0; i < N; i++ ) {
		cin >> num;
		
		if ( p.empty() || p.back() < num ) {
			p.push_back(num);
		} else {
			*lower_bound(p.begin(), p.end(), num) = num;
		}
	}
	cout << p.size();
}
