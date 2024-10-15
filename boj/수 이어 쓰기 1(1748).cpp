#include <iostream>
#include <vector>

using namespace std;

int pow(int d, int e) {
	int result = 1;
	while (e-- > 0) result *= d;
	return result;
}

int main() {
	int N;
	cin >> N;

	int result = 0;
	int n = 1;
	while (pow(10, n) <= N) {
		result += (pow(10, n)-1-(pow(10, n-1)-1))*n;
		n++;
	}

	result += (N-pow(10, n-1)+1)*n;
	cout << result << "\n";
	return 0;
}
