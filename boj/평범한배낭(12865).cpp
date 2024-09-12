#include <iostream>
#include <vector>

using namespace std;

struct obj {
	int w, v;
};

int N, K;
vector<obj> list;

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);

	cin >> N >> K;
	
	list.resize(N);
	for ( int i = 0; i < N; i++ )
		cin >> list[i].w >> list[i].v;
	
	vector<vector<int>> value(N, vector<int>(K+1, 0));
	for ( int i = 0; i < list.size(); i++ ) {
		for ( int w = 0; w <= K; w++ ) {
			if ( i >= 1 )
				value[i][w] = max(value[i][w], value[i-1][w]);
			if ( w >= list[i].w ) {
				if ( i == 0 )
					value[i][w] = list[i].v;
				else
					value[i][w] = max(value[i][w], value[i-1][w-list[i].w]+list[i].v);
			}
		}
	}
	
	cout << value[N-1][K];
}
