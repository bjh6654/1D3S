#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int len = friends.size();
    vector<vector<int>> arr(len, vector<int>(len, 0));
    vector<vector<int>> arr2(len, vector<int>(len, 0));
    
    map<string, int> m;
    for(int i = 0; i < friends.size(); i++) {
        m[friends[i]] = i;
    }
    
    for (string gift: gifts) {
        int idx = gift.find(" ");
        string s = gift.substr(0, idx);
        string e = gift.substr(idx+1, gift.size()-1);

        arr[m[s]][m[e]] += 1;
        arr2[m[e]][m[s]] += 1;
    }
    
    vector<int> gcount(len, 0);
    
    for (int r = 0; r < len; r++) {
        for (int c = r+1; c < len; c++) {
            if (arr[r][c] > arr[c][r]) {gcount[r]++; continue;}
            if (arr[c][r] > arr[r][c]) {gcount[c]++; continue;}
            int r_gi = accumulate(arr[r].begin(), arr[r].end(), 0) - accumulate(arr2[r].begin(), arr2[r].end(), 0);
            int c_gi = accumulate(arr[c].begin(), arr[c].end(), 0) - accumulate(arr2[c].begin(), arr2[c].end(), 0);
            if (r_gi > c_gi) {gcount[r]++; continue;}
            if (r_gi < c_gi) {gcount[c]++; continue;}
        }
    }
    
    return *max_element(gcount.begin(), gcount.end());
}