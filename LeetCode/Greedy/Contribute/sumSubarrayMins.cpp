#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    
    vector<int> st;
    vector<int> left(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.back()] >= arr[i]) {
            st.pop_back();
        }
        if (!st.empty()) left[i] = st.back();
        st.push_back(i);
    }

    st.clear();
    vector<int> right(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.back()] > arr[i]) {
            st.pop_back();
        }
        if (!st.empty()) right[i] = st.back();
        st.push_back(i);
    }

    int ans = 0;
    const int MOD = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        cout << left[i] << ' ' << right[i] << '\n';
        int l = i - left[i], r = right[i] - i;
        long long s = 1LL * (arr[i] * ((1LL * l % MOD * 1LL * r % MOD) % MOD)) % MOD;
        ans = (ans + s) % MOD;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}