#include <string>
#include <vector>
#include <iostream>

using namespace std;

int isAvail(string bin) {
    for (long long i = 0; i < bin.size(); i++) {
        if (bin[i] == '0') continue;
        long long min = 0, max = bin.size()-1;
        while (min < max) {
            long long root = min + (max-min)/2;
            if (bin[root] == '0') return 0;
            if (root == i) break;
            if (root > i) max = root;
            else min = root+1;
        }
    }
    return 1;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (long long n: numbers) {
        string bin = "";
        while (n > 0) {
            if (n%2) bin = "1" + bin;
            else bin = "0" + bin;
            n /= 2;
        }
        long long len = 1;
        while (len < bin.size()) {
            len = len*2+1;
        }
        while (len-bin.size()) {
            bin = "0" + bin;
        }
        answer.push_back(isAvail(bin));
    }
    return answer;
}