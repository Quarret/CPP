#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j]) break;
            cnt++;
        }
        a.push_back(cnt);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = n - 1 - i, j = i;
        for (; j < n; j++) {
            if (a[j] >= x) break;
        }

        if (j == n) return -1;
        for (int k = j; k > i; k--) {
            swap(a[k], a[k - 1]);
        }
        // if (a[i] < x) return -1;

        ans += j - i;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}