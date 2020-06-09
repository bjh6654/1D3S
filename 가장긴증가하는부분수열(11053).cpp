#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int N, num;
	cin >> N;
	
	vector<int> arr;
	for ( int i = 0; i < N; i++ ) {
		cin >> num;
		if ( arr.empty() || arr.back() < num ) {
			arr.push_back(num);	
		} else {
			vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), num);
			*iter = num;
		}
	}
	cout << arr.size();
}
