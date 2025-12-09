#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxNonOverlapping(vector<int>& nums, int target) {
    int n = nums.size(), ans = 0, sum = 0;
    unordered_set<int> st;

    for (int i = 0; i < n; i++) {
        st.insert(sum);
        sum += nums[i];

        if (st.contains(sum - target)) {
            ans++;
            st.clear();
            sum = 0;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
