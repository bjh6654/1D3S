#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<int> findDiff(string a, string b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i]) return {i+1, i+1};
    int size = a.size();
    return {size, size+1};
}

int solution(vector<string> words) {
    int answer = 0;
    
    sort(words.begin(), words.end());
    
    map<string, int> m;
    for (string w: words) m.insert({w, 0});
    
    for (int i = 1; i < words.size(); i++) {
        vector<int> v = findDiff(words[i-1], words[i]);
        m[words[i-1]] = max(v[0], m[words[i-1]]);
        m[words[i]] = max(v[1], m[words[i]]);
    }
    
    for (string w: words) {
        // cout << w << " : " << m[w] << "\n";
        answer += m[w];
    }
    return answer;
}