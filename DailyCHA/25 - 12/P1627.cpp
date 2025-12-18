#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, b;
    cin >> n >> b;

    unordered_map<int, int> cnt = {{0, 1}};

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0, sum = 0;
    bool find_b = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == b) {
            find_b = true;
        } else if (a[i] > b) {
            sum++;
        } else {
            sum--;
        }

        if (!find_b) {
            cnt[sum]++;
        } else {
            ans += cnt[sum];
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
