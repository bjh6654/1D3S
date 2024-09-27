#include <string>
#include <vector>

using namespace std;

int dist(int x, int y, int r, int c) {
    return abs(x-r) + abs(y-c);
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int d = abs(x-r)+abs(y-c);
    if (d > k || (k-d)%2) return "impossible";
    
    while (k) {
        if (x < n && dist(x+1, y, r, c) <= k-1) {
            x++;
            answer += "d";
        } else if (y > 1 && dist(x, y-1, r, c) <= k-1) {
            y--;
            answer += "l";
        } else if (y < m && dist(x, y+1, r, c) <= k-1) {
            y++;
            answer += "r";
        } else if (x > 1 && dist(x-1, y, r, c) <= k-1) {
            x--;
            answer += "u";
        } else {
            for (int i = 0; i < r-x; i++) answer += "d";
            for (int i = 0; i < c-y; i++) answer += "l";
            for (int i = 0; i < y-c; i++) answer += "r";
            for (int i = 0; i < x-r; i++) answer += "u";
            break;
        }
        k--;
    }
    
    return answer;
}