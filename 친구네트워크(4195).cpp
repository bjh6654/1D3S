#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> fnet(200000);
vector<int> size(200000);

int find(int a) {
	if ( fnet[a] == a )
		return a;
	return find(fnet[a]);
}

int getSize(int first, int second) {
	int net1 = find(first);
	int net2 = find(second);
	
	if ( net1 != net2 ) {
		fnet[net2] = fnet[net1];
		size[net1] += size[net2];
		size[net2] = 1;
	}
	
	return size[net1];
}

int main() {
	ios_base::sync_with_stdio(0);	cout.tie(0);	cin.tie(0);
	
	int T;
	cin >> T;
	
	while ( T-- ) {
		int N;
		cin >> N;
		
		int idx = 0;
		unordered_map<string, int> name;
		for ( int i = 0; i <= N*2; i++ ) {
			fnet[i] = i;
			size[i] = 1;
		}
		
		for ( int i = 0; i < N; i++ ) {
			string first, second;
			cin >> first >> second;
			if ( name.find(first) == name.end() )
				name[first] = idx++;
			if ( name.find(second) == name.end() )
				name[second] = idx++;
			
			cout << getSize(name[first], name[second]) << "\n";
		}
	}
}
