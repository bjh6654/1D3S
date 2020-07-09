#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	deque<int> que;
	for ( int i = 1; i <= N; i++ )
		que.push_back(i);
		
	int result = 0;
	for ( int i = 0; i < M; i++ ) {
		int loc;
		cin >> loc;
		
		if ( que.front() == loc ) {
			que.pop_front();
			N--;
		} else {
			for ( int i = 1; i < N; i++ )
				if ( que[i] == loc ) {
					result += min(N-i, i);
					while ( i-- ) {
						que.push_back(que.front());
						que.pop_front();
					}
					que.pop_front();
					N--;
					break;
				}
		}
	}
	cout << result;
}
