#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    rocks.insert(rocks.begin(), 0);
    sort(rocks.begin(), rocks.end());
    
    long long mini = 0, maxi = 1e9;
    
    while (mini < maxi) {
        long long check = mini + (maxi-mini)/2;
        
        int remove = 0;
        int minDist = 1e9;
        int pre = 0;
        for (int i = 1; i < rocks.size(); i++) {
            if (rocks[i]-rocks[pre] < check) {
                remove++;
            } else {
                minDist = min(minDist, rocks[i] - rocks[pre]);
                pre = i;
            }
        }
        if (distance - rocks[pre] < check) {
            remove++;
        } else {
            minDist = min(minDist, distance - rocks[pre]);
        }
        if (remove > n) {
            maxi = check;
        } else {
            mini = check + 1;
            answer = max(answer, minDist);
        }
    }
    return answer;
}