#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> link;
vector<int> number;

int findRoot(int n) {
    vector<int> visit(n, 1);
    for (vector<int> l: link) {
        visit[l[0]] = 0;
        visit[l[1]] = 0;
    }
    for (int i = 0; i < n; i++)
        if (visit[i]) return i;
    return 0;
}

vector<int> dfs(int idx, int check, int k) {
    int value = number[idx];
    if (value > check) return {0, (int)1e9};
    
    vector<int> left = {0, 0}, right = {0, 0};
    if (link[idx][0] != -1) {
        left = dfs(link[idx][0], check, k);
        if (left[1] > k) return left;
    }
    if (link[idx][1] != -1) {
        right = dfs(link[idx][1], check, k);
        if (right[1] > k) return right;
    }
    
    int cut = 0;
    if (value+left[0] > check) {
        cut++;
        left[0] = 0;
    }
    if (value+right[0] > check) {
        cut++;
        right[0] = 0;
    }
    if (value+left[0]+right[0] > check) {
        if (left[0] > right[0]) {
            cut++;
            left[0] = 0;
        } else {
            cut++;
            right[0] = 0;
        }
    }
    
    return {value + left[0] + right[0], cut+left[1]+right[1]};
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    link = links;
    number = num;
    
    int answer = 0;
    /*
    1. find root node.
    2. binary search : check = sum of num.
    3. dfs(postorder) >> if the summation of number is over the check, cut the line.
    4. while the dfs process if the count of cut line is over k-1, find next.
    */
    int root = findRoot(number.size());
    link.push_back({root, -1});
    number.push_back(0);
    
    int min = 0, max = 1e8+1;
    while (min < max) {
        int check = min + (max - min)/2;
        vector<int> result = dfs(number.size()-1, check, k);
        if (result[1] <= k-1) {
            max = check;
        } else {
            min = check + 1;
        }
    }
    
    // cout << min;
    
    return min;
}