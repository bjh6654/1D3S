#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    unsigned long long min = 0;
    unsigned long long max = -1;
    
    while (min < max) {
        unsigned long long check = min + (max-min)/2;
        unsigned long long passed = 0;
        for (int t: times) {
            passed += check/t;
            if (passed >= n) {
                max = check;
            }
        }
        if (passed < n) {
            min = check+1;
        }
    }
    
    return min;
}