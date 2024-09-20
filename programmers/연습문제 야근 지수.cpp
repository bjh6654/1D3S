#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    sort(works.begin(), works.end(), greater<>());
    
    unsigned long long min = 0, max = works[0];
    
    while (min < max) {
        unsigned long long check = min + (max - min)/2;
        
        unsigned long long consume = 0;
        for (int t: works) {
            consume += t > check ? t - check : 0;
            if (consume > n) {
                min = check+1;
                break;
            }
        }
        if (consume <= n) {
            max = check;
        }
    }
    
    for (int i = 0; i < works.size(); i++) {
        int t = works[i];
        if (t > min) {
            n -= t - min;
            works[i] = min;
        }
    }
    
    for (int t: works) {
        if (n-- > 0) {
            t = t-1 >= 0 ? t-1 : 0;
            answer += t*t;
        } else {
            answer += t*t;
        }
    }
    
    return answer;
}