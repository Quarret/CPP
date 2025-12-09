#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    int n = barcodes.size(), m = 0;
    unordered_map<int, int> cnt;
    for (int x : barcodes) {
        cnt[x]++;
        m = max(m, cnt[x]);
    }
    
    vector<pair<int, int>> a(cnt.begin(), cnt.end());
    ranges::sort(a, {}, [&](auto &p) {
        return -p.second;
    });

    vector<int> ans(n);
    int i = 0;
    for (auto [x, c] : a) {
        while (c) {
            ans[i] = x;
            i += 2;
            c--;

            if (i >= n) {
                i = 1; // 填完偶数填奇数
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
