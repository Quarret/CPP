#include <bits/stdc++.h>
using ll = long long;
using namespace std;


long long countGoodSubarrays(vector<int>& nums) {
    using ll = long long;
    int n = nums.size();
    vector<ll> st = {-1};
    vector<ll> left(n, -1);
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        while (st.size() > 1 && (nums[st.back()] | x) == x) {
            st.pop_back();
        }
        left[i] = st.back();
        st.push_back(i);
    }

    st = {n};
    vector<ll> right(n, n);
    for (int i = n - 1; i >= 0; i--) {
        int x = nums[i];
        while (st.size() > 1 && nums[st.back()] != x && (nums[st.back()] | x) == x) {
            st.pop_back();
        }
        right[i] = st.back();
        st.push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * (i - left[i]) * (right[i] - i);
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}