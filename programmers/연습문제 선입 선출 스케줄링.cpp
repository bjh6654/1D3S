#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int solution(int n, vector<int> cores) {
    int min = 0, max = 5e8;
    int pre = 0;
    if (n < cores.size()) return n;
    
    while (min < max) {
        long check = min + (max - min)/2;
        
        long passed = 0;
        for (int c: cores) {
            passed += check/c+1;
            if (passed >= n) {
                max = check;
                break;
            }
        }
        if (passed < n) {
            min = check+1;
            pre = passed;
        }
    }
    
    n -= pre;

    for (int i = 0; i < cores.size(); i++) {
        int c = cores[i];
        if (min % c == 0) {
            if (--n == 0) return i+1;
        }
    }
    return -1;
}