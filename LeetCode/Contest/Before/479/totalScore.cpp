#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
    using i64 = long long;
    int n = damage.size();
    i64 ans = 0;
    vector<i64> pre(n + 1);

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + damage[i];
        int low = pre[i + 1] = requirement[i] - hp;
        int j = lower_bound(pre.begin(), pre.begin() + i + 1, low) - pre.begin();
        ans += 1LL * (i - j + 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
