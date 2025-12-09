#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector f(numRows + 1, vector<int>(numRows + 1));
    f[0][0] = 1;
    vector<vector<int>> ans(numRows);
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < i + 1; j++) {
            f[i + 1][j + 1] = f[i][j] + f[i][j + 1];
            ans[i].push_back(f[i + 1][j + 1]);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
