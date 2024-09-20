#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<string> a, vector<string> b) {
    for (int i = 0; i < min(a[0].size(), b[0].size()); i++) {
        if (tolower(a[0][i]) != tolower(b[0][i])) return tolower(a[0][i]) < tolower(b[0][i]);
    }
    if (a[0].size() != b[0].size()) return a[0].size() < b[0].size();
    
    return stoi(a[1]) < stoi(b[1]);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<vector<string>> list;
    for (string file: files) {
        string head = "", number = "", tail = "";
        for (char c: file) {
            if (c >= '0' && c <= '9') {
                if (!tail.size() && number.size() < 5) number += c;
                else tail += c;
            } else {
                if (!number.size()) head += c;
                else tail += c;
            }
        }
        list.push_back({head, number, tail});
    }
    
    stable_sort(list.begin(), list.end(), cmp);
    for (vector<string> l: list) {
        answer.push_back(l[0]+l[1]+l[2]);
    }
    return answer;
}