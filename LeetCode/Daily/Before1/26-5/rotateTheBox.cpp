#include <bits/stdc++.h>
using ll = long long;
using namespace std;


vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
    int m = boxGrid.size(), n = boxGrid[0].size();
    vector pre(m, vector<int>(n, 0));
    vector ans(n, vector<char>(m, '.'));
    
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (boxGrid[i][j] == '#') cnt++;
            else if (boxGrid[i][j] == '*') {
                pre[i][j] = cnt;
                cnt = 0;
            }
        }
        if (boxGrid[i][n - 1] != '*') pre[i][n - 1] = cnt;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (boxGrid[i][j] == '*') ans[j][m - 1 - i] = '*';
            if (!pre[i][j]) continue;
            for (int k = boxGrid[i][j] == '*'; pre[i][j]; k++, pre[i][j]--) {
                ans[j - k][m - 1 - i] = '#';
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}