#include <bits/stdc++.h>
using ll = long long;
using namespace std;


bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    int n = mat.size();
    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        for (auto &row : mat) {
            ranges::reverse(row);
        }

        if (mat == target) return true;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}