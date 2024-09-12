#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    vector<vector<int>> table(board.size(), vector<int>(board[0].size(), 0));
    for (vector<int> s: skill) {
        int d = s[0] == 1 ? -s[5] : s[5];
        int sr = s[1], sc = s[2];
        int er = s[3], ec = s[4];
        
        table[sr][sc] += d;
        if (er+1 < board.size()) table[er+1][sc] -= d;
        if (ec+1 < board[0].size()) table[sr][ec+1] -= d;
        if (er+1 < board.size() && ec+1 < board[0].size()) table[er+1][ec+1] += d;
    }
    
    for (int r = 0; r < board.size(); r++) {
        for (int c = 1; c < board[0].size(); c++) {
            table[r][c] += table[r][c-1];
        }
    }
    for (int c = 0; c < board[0].size(); c++) {
        for (int r = 1; r < board.size(); r++) {
            table[r][c] += table[r-1][c];
        }
    }
    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board[0].size(); c++) {
            if (board[r][c] + table[r][c] > 0) answer++;
        }
    }
    return answer;
}

/**
효율성 통과를 위해 2차원 배열에서의 누적합 사용
**/