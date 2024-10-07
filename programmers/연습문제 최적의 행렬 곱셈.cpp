#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int n = matrix_sizes.size();
    vector<vector<int>> result(n, vector<int>(n, 1e9));
    for (int r = 0; r < n; r++)
        for (int s = 0; (s+r) < n; s++) {
            if (r == 0) result[s][s+r] = 0;
            for (int p = s; p < s+r; p++)
                result[s][s+r] = min(result[s][p]+result[p+1][s+r]+(matrix_sizes[s][0]*matrix_sizes[p][1]*matrix_sizes[s+r][1]), result[s][s+r]);
        }
    
    return result[0][n-1];
}

//     0   1   2
// 0   0  150   
// 1       0  180
// 2           0
