#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans1 = 3 * n, ans2 = 3 * m, diff = ans1 - ans2;
    for (int i = 0; i < n; i++) {
        int d = a[i];
        i = lower_bound(a.begin(), a.end(), d + 1) - a.begin();
        int scoreA = i * 2 + (n - i) * 3;

        int idx = lower_bound(b.begin(), b.end(), d + 1) - b.begin();
        int scoreB = (idx + 1) * 2 + (m - idx) * 3;

        // cout << scoreA << ' ' << scoreB << '\n';
        if (scoreA - scoreB > diff) {
            diff = scoreA - scoreB;
            ans1 = scoreA;
            ans2 = scoreB;
        }
    }

    for (int i = 0; i < m; i++) {
        int d = b[i];
        i = lower_bound(b.begin(), b.end(), d + 1) - b.begin();
        int scoreB = i * 2 + (m - i) * 3;

        int idx = lower_bound(a.begin(), a.end(), d + 1) - a.begin();
        int scoreA = idx * 2 + (n - idx) * 3;

        // cout << scoreA << ' ' << scoreB << '\n';
        if (scoreA - scoreB > diff) {
            diff = scoreA - scoreB;
            ans1 = scoreA;
            ans2 = scoreB;
        }
    }

    cout << ans1 << ":" << ans2 << '\n';
}

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> nums;
    for (int x : a) {
        nums.emplace_back(x, 0);
    }

    for (int x : b) {
        nums.emplace_back(x, 1);
    }

    sort(nums.begin(), nums.end());
    int ans1 = 3 * n, ans2 = 3 * m, score1 = 3 * n, score2 = 3 * m;
    int t = nums.size();

    for (int i = 0; i < t; i++) {
        auto [d, num] = nums[i];
        while (i < t && nums[i].first == d && nums[i].second == num) {
            num == 0 ? score1 : score2 -= 1;
            i++;
        }

        if (score1 - score2 > ans1 - ans2) {
            ans1 = score1;
            ans2 = score2;
        }
    }

    cout << ans1 << ":" << ans2 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
