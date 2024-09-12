#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line {
	int s, e;
};

bool comp(line a, line b) {
	return a.s < b.s;
}

int main() {
	int N, s,e;
	cin >> N;
	
	vector<line> p;
	for ( int i = 0; i < N; i++ ) {
		cin >> s >> e;
		p.push_back({s, e});
	}
	
	sort(p.begin(), p.end(), comp);
	
	vector<int> dest;
	for ( line l : p ) {
		if ( dest.empty() || dest.back() < l.e ) {
			dest.push_back(l.e);
		} else {
			*lower_bound(dest.begin(), dest.end(), l.e) = l.e;
		}
	}
	
	cout << N - dest.size();
}
