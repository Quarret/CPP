#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> mat(matrix.begin(), matrix.end());
    
    vector<int> row(m), col(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                if (!row[i]) {
                    row[i] = 1;
                    for (int k = 0; k < n; k++) mat[i][k] = 0;
                }

                if (!col[j]) {
                    col[j] = 1;
                    for (int k = 0; k < m; k++) mat[k][j] = 0;
                }
            }
        }
    }

    matrix = mat;
}

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> x, y;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!matrix[i][j]) {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }

    for (int xx : x) {
        for (int k = 0; k < n; k++) {
            matrix[xx][k] = 0;
        }
    }

    for (int k = 0; k < m; k++) {
        for (int yy : y) {
            matrix[k][yy] = 0;
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
