#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(int level, vector<int> diffs, vector<int> times, long long limit) {
    long long sum = 0;
    for (int i = 1; i < diffs.size(); i++) {
        long long wrong = max(diffs[i]-level, 0);
        sum += times[i-1]*(wrong);
        sum += times[i]*(wrong+1);
    }
    return sum <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    diffs.insert(diffs.begin(), 0);
    times.insert(times.begin(), 0);
    
    int lower = 1;
    int upper = 1e5;
    
    while (lower < upper) {
        // cout << lower << ", " << upper << "\n";
        int answer = (lower+upper)/2;
        if (!check(answer, diffs, times, limit)) {
            lower = answer+1;
        } else {
            upper = (lower+upper)/2;
        }
    }
    
    return lower;
}

// 2024-09-11