#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

int diffChar(string a, string b) {
    int count = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i]) count++;
    return count;
}

map<string, int> m;

int bfs(queue<string> q, int step, string target, vector<string> words) {
    queue<string> next;
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        if (s == target) return step;
        
        for (string w: words) {
            if (diffChar(s, w) == 1 && m[w]) {
                m[w] = 0;
                next.push(w);
            }
        }
    }
    
    if (next.empty()) return 0;
    return bfs(next, step+1, target, words);
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<string> q;
    q.push(begin);
    

    for (string s: words) {
        m.insert({s, 1});
    }
    m[begin] = 0;
    answer = bfs(q, 0, target, words);
    return answer;
}