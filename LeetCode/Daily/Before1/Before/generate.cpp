#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    ans[0].push_back(1);
    
    for (int i = 1; i < numRows; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j - 1 < 0 || j >= ans[i - 1].size()) ans[i].push_back(1);
            else ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
