#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    using ll = long long;
    
    int n = nums.size();
    vector<int> min_left(n, -1), min_right(n, n);
    vector<int> max_left(n, -1), max_right(n, n);
    
    vector<int> st1, st2;
    for (int i = 0; i < n; i++) {
        while (!st1.empty() && nums[st1.back()] >= nums[i]) {
            st1.pop_back();
        }
        if (!st1.empty()) min_left[i] = st1.back();
        st1.push_back(i);
        
        while (!st2.empty() && nums[st2.back()] <= nums[i]) {
            st2.pop_back();
        }
        if (!st2.empty()) max_left[i] = st2.back();
        st2.push_back(i);
    }
    
    st1.clear();
    st2.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!st1.empty() && nums[st1.back()] > nums[i]) {
            st1.pop_back();
        }
        if (!st1.empty()) min_right[i] = st1.back();
        st1.push_back(i);
        
        while (!st2.empty() && nums[st2.back()] < nums[i]) {
            st2.pop_back();
        }
        if (!st2.empty()) max_right[i] = st2.back();
        st2.push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll l1 = i - min_left[i], r1 = min_right[i] - i;
        ll l2 = i - max_left[i], r2 = max_right[i] - i;
        // cout << "min" << ' ' << l1 << ' ' << r1 << '\n';
        // cout << "max" << ' ' << l2 << ' ' << r2 << '\n';
        ans += nums[i] * (l2 * r2 - l1 * r1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}