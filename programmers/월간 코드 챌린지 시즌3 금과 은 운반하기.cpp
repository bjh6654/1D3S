#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    unsigned long long low = 0, high = 4e14;
    
    if ( a == 0 && b == 0 ) return 0;
    
    while (low < high) {
        unsigned long long check = low + (high - low)/2;
        unsigned long long total = 0, gold = 0, silver = 0;
        for (int i = 0; i < g.size(); i++) {
            long long count = (check+t[i])/(2L*t[i]);
            long long maxWeight = min(count*w[i], (long long)(g[i]+s[i]));
            total += maxWeight;
            gold += min((long long)g[i], maxWeight);
            silver += min((long long)s[i], maxWeight);
            
            if (total >= (long long)a+b && gold >= a && silver >= b) {
                high = check;
            }
        }
        if (total < (long long)a+b || gold < a || silver < b) {
            low = check + 1;
        }
    }
    return low;
}