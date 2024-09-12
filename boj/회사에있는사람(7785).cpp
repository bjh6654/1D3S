#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<string> logs;
	
	for ( int i = 0; i < N; i++ ) {
		string name, l;
		cin >> name >> l;
		logs.push_back(name);
	}
	
	sort(logs.begin(), logs.end());
	
	stack<string> enter;
	
	for ( string s : logs ) {
		if ( enter.empty() )
			enter.push(s);
		else if ( enter.top() != s )
			enter.push(s);
		else
			enter.pop();
	}
	
	while ( !enter.empty() ) {
		cout << enter.top() << "\n";
		enter.pop();
	}
}
