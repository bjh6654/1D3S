#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<long long> result(n+1, 0);
    result[0] = 1;
    for (int m: money)
        for (int i = 1; i <= n; i++)
            if (i-m >= 0 && result[i-m])
                result[i] += result[i-m];
    return result[n];
}
