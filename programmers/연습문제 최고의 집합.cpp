#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s) return {-1};
    answer = vector<int>(n, s/n);
    s %= n;
    for (int i = n-1; s > 0; i--) {
        answer[i]++;
        s--;
    }
    return answer;
}