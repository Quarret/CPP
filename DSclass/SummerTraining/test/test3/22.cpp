#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 计算前缀和
void computePrefixSum(const vector<vector<int>>& matrix, vector<vector<int>>& zero_count) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            zero_count[i][j] = (matrix[i][j] == 0);
            if (i > 0) zero_count[i][j] += zero_count[i-1][j];
            if (j > 0) zero_count[i][j] += zero_count[i][j-1];
            if (i > 0 && j > 0) zero_count[i][j] -= zero_count[i-1][j-1];
            //cout << zero_count[i][j] << ' ';
        }
        //cout << '\n';
    }
}

// 计算以 (i, j) 为右下角的最大稠密正方形的边长
int largestDenseSquare(const vector<vector<int>>& matrix, int f) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    // 初始化 dp 和前缀和数组
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<int>> zero_count(n, vector<int>(m, 0));
    computePrefixSum(matrix, zero_count);
    
    int max_side_length = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //if (matrix[i][j] == 1) {
                dp[i][j] = 1;
                if (i > 0 && j > 0) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    //以(i, j)为右下角能形成的最大正方形的边长
                }
                
                // 检查每个正方形是否稠密
                for (int k = dp[i][j]; k > 0; --k) {
                    int x1 = i - k + 1, y1 = j - k + 1;
                    int x2 = i, y2 = j;
                    int zero_count_in_square = zero_count[x2][y2];
                    
                    if (x1 > 0) zero_count_in_square -= zero_count[x1-1][y2];
                    if (y1 > 0) zero_count_in_square -= zero_count[x2][y1-1];
                    if (x1 > 0 && y1 > 0) zero_count_in_square += zero_count[x1-1][y1-1];
                    
                    if (zero_count_in_square <= f) {
                        max_side_length = max(max_side_length, k);
                        break;
                    }
                }
            //}
            }
    }
    
    return max_side_length;
}

int main() {
    int n, m, f;
    cin >> n >> m >> f;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    cout << largestDenseSquare(matrix, f) << endl;
    return 0;
}
