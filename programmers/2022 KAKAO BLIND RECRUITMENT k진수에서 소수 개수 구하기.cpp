#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(string num) {
    long long n = stoll(num);
    if (n == 1) return false;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (!(n%i)) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string num = "";
    while (n) {
        num = to_string(n%k)+num;
        n /= k;
    }
    string sn = "";
    for (int i = 0; i < num.size(); i++) {
        if (num[i] != '0') {
            sn += num[i];
        } else {
            if (sn.size() && isPrime(sn)) answer++;
            sn = "";
        }
    }
    if (sn.size() && isPrime(sn)) answer++;
    
    return answer;
}

/**
소수 판별에서 시간 초과 -> n의 약수는 n의 제곱근 이하에서 존재해야 쌍이되는 약수가 존재하기 때문에 제곱근까지만 확인
**/