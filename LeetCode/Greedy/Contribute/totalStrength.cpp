#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int totalStrength(vector<int>& strength) {
    using ll = long long;
    const int MOD = 1e9 + 7;
    int n = strength.size();

    vector<int> left(n, -1), right(n, n);
    vector<int> st = {-1};
    for (int i = 0; i < n; i++) {
        while (st.size() > 1 && strength[st.back()] >= strength[i]) {
            right[st.back()] = i;
            st.pop_back();
        }
        if (!st.empty()) left[i] = st.back();
        st.push_back(i);
    }

    ll s = 0; // 前缀和
    vector<ll> ss(n + 2, 0); // 前缀和的前缀和
    for (int i = 1; i <= n; i++) {
        s += strength[i - 1];
        ss[i + 1] = (ss[i] + s) % MOD;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll l = left[i] + 1, r = right[i] - 1; // 左闭右闭区间
        ll tot = ((i - l + 1) * (ss[r + 2] - ss[i + 1]) - (r - i + 1) * (ss[i + 1] - ss[l])) % MOD;
        ans = (ans + strength[i] * tot) % MOD;
    }

    return (ans + MOD) % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}