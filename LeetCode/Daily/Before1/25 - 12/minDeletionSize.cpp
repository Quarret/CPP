#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minDeletionSize(vector<string>& strs) {
    int ans = 0;
    int n = strs.size(), m = strs[0].size();
    for (int j = 0; j < m; j++) {
        int c = -1;
        for (int i = 0; i < n; i++) {
            if (strs[i][j] - 'a' >= c) {
                c = strs[i][j] - 'a';
                continue;
            }
            ans++;
            break;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
