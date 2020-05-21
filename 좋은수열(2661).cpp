#include <iostream>

using namespace std;

int N;

pair<string, string> make_string(int len, string num) {
	string one = "", two = "";
	for ( int i = 0; i < len; i++ ) {
		one += num.back();
		num.pop_back();
	}
	for ( int i = 0; i < len; i++ ) {
		two += num.back();
		num.pop_back();
	}
	return make_pair(one, two);
}

bool check(string num) {
	for ( int i = 1; i <= num.length()/2; i++ ) {
		pair<string, string> p = make_string(i, num);
		if ( p.first == p.second )
			return false;
	}
	return true;
}

string dfs(int count, string num) {
	if ( count == N ) {
		return num;
	}
	for ( int i = 1; i <= 3; i++ ) {
		char c = i + 48;
		if ( check(num+c) ) {
			string t = dfs(count+1, num+c);
			if ( t != "" )
				return t;
		}
	}
	return "";
}

int main() {
	cin >> N;
	cout << dfs(0, "");
	
}
