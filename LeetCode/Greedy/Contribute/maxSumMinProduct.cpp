#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxSumMinProduct(vector<int>& nums) {
    using ll = long long;
    int n = nums.size(), MOD = 1e9 + 7;
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = (pre[i] + nums[i]);
    }
    
    vector<ll> st;
    vector<int> left(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.back()] >= nums[i]) {
            st.pop_back();
        }
        if (!st.empty()) left[i] = st.back();
        st.push_back(i);
    }

    st.clear();
    vector<int> right(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.back()] >= nums[i]) {
            st.pop_back();
        }
        if (!st.empty()) right[i] = st.back();
        st.push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = left[i], r = right[i];
        ll s = ((pre[r] - pre[l + 1]));
        ans = max(ans, (1LL * nums[i] * s));
    }

    return ans % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}