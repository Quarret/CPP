#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string getPermutation(int n, int k) {
    vector<string> ans;
    string path(n, '0');
    int mask = 0;

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(path);
            return;
        }

        for (int k = 1; k <= n; k++) {
            if (mask >> k & 1) continue;
            mask |= 1 << k;
            path[i] = k + '0';
            dfs(i + 1);
            mask ^= 1 << k; 
        }
    };

    dfs(0);
    ranges::sort(ans);
    return ans[k - 1];
}

string getPermutation(int n, int k) {
    k--;

    int frac = 1;
    for (int i = 1; i <= n - 1; i++) {
        frac *= i; // (n - 1)!
    }

    int mask = 0;
    string ans(n, '0');
    for (int i = 0; i < n; i++) {
        int cnt = k / frac, sum = 0;
        
        for (int x = 1; x <= n; x++) {
            if (mask >> x & 1) continue;
            if (cnt == sum) {
                ans[i] += x;
                mask |= 1 << x;
            }
            sum++;
        }
        
        k -= frac * cnt;
        frac /= max((n - 1 - i), 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}