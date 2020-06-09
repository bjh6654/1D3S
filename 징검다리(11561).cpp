#include <iostream>
#include <vector>

using namespace std;

unsigned long long sum(long long num) {
	return (num*(num+1LL))/2LL;
}

unsigned long long getStep(long long N) {
	unsigned long long min = 1LL, max = N, mid = 1LL;
	while ( min < max ) {
		mid = (min+max)/2LL;
		
		unsigned long long value = sum(mid);
		if ( value <= N )
			min = mid+1LL;
		else
			max = mid;
	}
	while ( sum(mid) > N )
		mid--;
	return mid;
}

int main() {
	unsigned long long T;
	scanf("%llu", &T);
	
	while ( T-- ) {
		unsigned long long N;
		scanf("%llu", &N);
	
		printf("%llu\n", getStep(N));
	}
}
