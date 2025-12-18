#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // 转置
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // 行反转
    for (auto &row : matrix) {
        ranges::reverse(row);
    }
}

// 沿中心 180° 旋转
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    for (int j = 0; j < n; j++) {
        int i = 0, k = n - 1;
        while (i < k) {
            swap(matrix[i++][j], matrix[k--][j]);
        }
    }

    // 行反转
    for (auto &row : matrix) {
        ranges::reverse(row);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
