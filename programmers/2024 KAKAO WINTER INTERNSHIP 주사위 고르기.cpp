#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> sel;
vector<int> unselect;
vector<int> result;
vector<vector<int>> dice;
vector<int> list;
priority_queue<int, vector<int>, greater<int>> sumList_1, sumList_2;
int maxV = 0;

void permutation(int d, int size) {
    if (d == size) {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < list.size(); i++) {
            s1 += dice[sel[i]][list[i]];
            s2 += dice[unselect[i]][list[i]];
        }
        sumList_1.push(s1);
        sumList_2.push(s2);
        return;
    }
    
    for (int i = 0; i < 6; i++) {
        list[d] = i;
        permutation(d+1, size);
    }
}

void dfs(int s, int d) {
    if (d == dice.size()/2) {
        sumList_1 = priority_queue<int, vector<int>, greater<int>>();
        sumList_2 = priority_queue<int, vector<int>, greater<int>>();
        unselect.clear();
        
        for (int i = 0; i < dice.size(); i++) {
            if (find(sel.begin(), sel.end(), i) == sel.end()) unselect.push_back(i);
        }
        permutation(0, dice.size()/2);
        
        int v = 0;
        while (sumList_1.size() && sumList_2.size()) {
            if (sumList_1.top() > sumList_2.top()) {
                v+=sumList_1.size();
                sumList_2.pop();
            } else if (sumList_1.top() < sumList_2.top()) {
                sumList_1.pop();
            } else {
                sumList_1.pop();
            }
        }
        if (maxV < v) {
            maxV = v;
            result = sel;
        }
        
        return;
    }
    
    for (int i = s+1; i < dice.size(); i++) {
        sel[d] = i;
        dfs(i, d+1); 
    }
    return;
}

vector<int> solution(vector<vector<int>> dices) {
    sel = vector<int>(dices.size()/2, 0);
    unselect = vector<int>(dices.size()/2, 0);
    dice = dices;
    list = vector<int>(dices.size()/2);
    
    dfs(-1, 0);
    for (int i = 0; i < result.size(); i++) result[i] += 1;
    return result;
}