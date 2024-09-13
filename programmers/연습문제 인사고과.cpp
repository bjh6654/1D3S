#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    vector<int> target = scores[0];
    
    sort(scores.begin(), scores.end(), cmp);
    
    int m = scores[0][0];
    int mscore = scores[0][1];
    
    for (vector<int> s: scores) {
        if ( m > s[0] && mscore > s[1] ) {
            if (s[0] == target[0] && s[1] == target[1]) return -1;
        } else {
            if (s[0]+s[1] > target[0]+target[1]) answer++;
        }
        mscore = max(mscore, s[1]);
    }
    
    
    return answer;
}