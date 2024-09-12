#include <iostream>
#include <queue>

using namespace std;

bool prime[10000];

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	int T;
	cin >> T;
	
	fill(prime, prime+10000, true);
	for ( int i = 2; i <= 9999; i++ ) {
		if ( prime[i] ) {
			int p = i+i;
			while ( p <= 9999 ) {
				prime[p] = false;
				p += i;
			}
		}
	}
	
	while ( T-- ) {
		string first;
		int second;
		cin >> first >> second;
		
		queue<pair<string, int>> que;
		que.push({first, 0});
		
		int count[10000];
		fill(count, count+10000, 2e9);
		count[stoi(first)] = 0;
		while ( !que.empty() ) {
			string num = que.front().first;
			int c = que.front().second;
			que.pop();
			
			for ( int i = 0; i < 4; i++ ) {
				for ( char n = '0'; n <= '9'; n++ ) {
					string tmp = num;
					tmp[i] = n;
					int number = stoi(tmp);
					if ( number >= 1000 && prime[number] && count[number] > c+1 ) {
						count[number] = c+1;
						que.push({tmp, c+1});
					}
				}
			}
		}
		if ( count[second] == 2e9 )
			cout << "Impossible\n";
		else
			cout << count[second] << "\n";
	}
}
