#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    vector<int> cost(1001, -1);
    vector<int> que;
    
    int i;
    int n = cards.size();
    for (i = 0; i < n/3; i++) {
        cost[cards[i]] = 0;
        que.push_back(cards[i]);
    }
    
    priority_queue<int, vector<int>, greater<int>> pair;
    for (int r = 0; r < que.size(); r++) {
        for (int c = r+1; c < que.size(); c++) {
            if (que[r]+que[c] == n+1) pair.push(0);
        }
    }
    
    while (++answer && i+1 < cards.size()) {
        int num1 = cards[i++];
        int num2 = cards[i++];
        cost[num1] = 1;
        cost[num2] = 1;
        if (cost[n+1-num1] != -1) pair.push(cost[n+1-num1]+cost[num1]);
        if (cost[n+1-num2] != -1) pair.push(cost[n+1-num2]+cost[num2]);

        if (pair.size() && coin >= pair.top()) {
            coin -= pair.top();
            pair.pop();
        } else {
            break;
        }
    }
    
    
    return answer;
}