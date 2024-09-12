#include <iostream>

using namespace std;

int count_6(int num) {
	int count = 0;
	while ( num > 0 ) {
		if ( num % 10 == 6 ) {
			count += 1;
			if ( count == 3 )
				return true;
		} else {
			count = 0;
		}
		num /= 10;
	}
	return false;
}

int main() {
	 int N;
	 cin >> N;
	 
	 int num = 0;
	 while ( N > 0 ) {
	 	num++;
	 	if ( count_6(num) )
	 		N -= 1;
	 }
	 cout << num;
}
