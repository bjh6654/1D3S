#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    
    map<string, int> m;
    vector<set<int>> count(id_list.size());
    for (int i = 0; i < id_list.size(); i++) {
        m.insert({id_list[i], i});
    }

    for (string r: report) {
        int idx = r.find(' ');
        string a = r.substr(0, idx);
        string b = r.substr(idx+1, r.size());
        count[m[b]].insert(m[a]);
    }
    
    for (set<int> s: count) {
        if (s.size() >= k) for (int i: s) answer[i]++;
    }

    return answer;
}

// 2024-09-12