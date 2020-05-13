#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[] = { 0, -1, 1, 0, 0 };
int q[] = { 0, 0, 0, 1, -1 };

struct shark {
	int r, c, s, d, z;
};

bool comp(shark a, shark b) {
	if ( a.c == b.c )
		return a.r < b.r;
	return a.c < b.c;
}

bool comp_size(shark a, shark b) {
	return a.z > b.z;
}

int getShark(vector<shark> &sharks, int idx) {
	sort(sharks.begin(), sharks.end(), comp);
	
	vector<shark>::iterator iter;
	for ( iter = sharks.begin(); iter != sharks.end(); iter++ ) {
		if ( (*iter).c == idx ) {
			int size = (*iter).z;
			sharks.erase(iter);
			return size;
		}
	}
	return 0;
}

vector<shark> moveShark(vector<shark> sharks, int R, int C) {
	vector< vector<bool> > visit(R+1, vector<bool>(C+1, false));
	vector<shark> result;
	
	sort(sharks.begin(), sharks.end(), comp_size);
	
	vector<shark>::iterator iter;
	for ( iter = sharks.begin(); iter != sharks.end(); iter++ ) {
		shark a = *iter;
		if ( a.d == 1 || a.d == 2 ) {
			a.r = a.r + (p[a.d] * a.s);
			while ( a.r < 0 || a.r > R ) {
				if ( a.r < 0 )
					a.r *= -1;
				else
					a.r = R - abs(R - a.r);
				a.d = (a.d == 1 ? 2 : 1);
			}
		} else {
			a.c = a.c + (q[a.d] * a.s);
			while ( a.c < 0 || a.c > C ) {
				if ( a.c < 0 )
					a.c *= -1;
				else
					a.c = C - abs(C - a.c);
				a.d = (a.d == 3 ? 4 : 3);
			}
		}

		if ( !visit[a.r][a.c] ) {
			visit[a.r][a.c] = true;
			result.push_back(a);
		}
	}

	return result;
}

int main() {
	int R, C, M;
	vector<shark> sharks;
	
	cin >> R >> C >> M;
	R -= 1;
	C -= 1;
	
	for ( int i = 0; i < M; i++ ) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharks.push_back({r-1, c-1, s, d, z});
	}
	
	int sum = 0;
	for ( int i = 0; i <= C; i++ ) {
		sum += getShark(sharks, i);
		sharks = moveShark(sharks, R, C);
	}
	
	cout << sum;
}
