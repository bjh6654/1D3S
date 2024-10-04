// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

int dfs(long long n, int star) {
    if (n == 1) {
        if (star == 0) return 1;
        else return 0;
    }
    if (n < pow(3, star/2)) return 0;
    
    int result = 0;
    if (n%3 == 0 && star >= 2) result += dfs(n/3, star-2);
    result += dfs(n-1, star+1);
    
    return result;
}

int solution(int n) {
    int answer = 0;
    
    answer = dfs(n-2, 2);
    
    return answer;
}