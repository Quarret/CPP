#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minMaxSums(vector<int>& nums, int k) {
    const int MOD = 1e9 + 7;
    using ll = long long;
    
    int n = nums.size();
    ranges::sort(nums);

    vector<int> min_left(n, -1);
    vector<int> min_right(n, n);
    vector<int> st = {-1};
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.back() >= nums[i]) {
            min_right[st.back()] = i;
            st.pop_back();
        }
        min_left[i] = st.back();
        st.push_back(i);
    }

    st.clear();
    vector<int> max_left(n, -1);
    vector<int> max_right(n, n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.back() <= nums[i]) {
            max_right[st.back()] = i;
            st.pop_back();
        }
        max_left[i] = st.back();
        st.push_back(i);
    }

    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}