#include <iostream>

using namespace std;

int cost[10001]; 

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int N, p;
	cin >> N;
	
	for ( int i = 1; i <= N; i++ ) {
		cin >> p;
		cost[i] = max(cost[i], p);
		for ( int a = i+1; a <= N; a++ )
			cost[a] = max(cost[a-i]+p, cost[a]);
	}
	cout << cost[N];	
}
