#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minDeletionSize(vector<string>& strs) {
    int n = strs.size(), m = strs[0].size();

    int ans = 0;
    vector<int> isGreated(n, 0);
    for (int j = 0; j < m; j++) {
        int ok = 1;
        for (int i = 1; i < n; i++) {
            if (isGreated[i]) continue;
            if (strs[i][j] < strs[i - 1][j]) {
                ok = 0;
                ans++;
                break;
            }
        }

        if (ok) {
            for (int i = 1; i < n; i++) {
                if (isGreated[i]) continue;
                if (strs[i][j] > strs[i  -1][j]) {
                    isGreated[i] = 1;
                }
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
