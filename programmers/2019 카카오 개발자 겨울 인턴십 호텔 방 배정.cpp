#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<long long, long long> used;

long long findNext(long long r) {
    if (used.find(r) == used.end()) return r;
    return used[r] = findNext(used[r]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (long long r: room_number) {
        if (used.find(r) == used.end()) {
            used.insert({r, findNext(r+1)});
            answer.push_back(r);
        } else {
            long long next = findNext(r);
            used.insert({next, findNext(next+1)});
            answer.push_back(next);
        }
    }
    return answer;
}