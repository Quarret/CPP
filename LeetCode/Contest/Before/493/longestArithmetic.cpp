#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestArithmetic(vector<int>& nums) {
    int n = nums.size();
    
    int ans = 2;
    vector<int> l(n, 1), r(n, 1);


    l[1] = 2;
    for (int i = 2; i < n; i++) {
        if (nums[i - 1] - nums[i] == nums[i - 2] - nums[i - 1]) {
            l[i] = l[i - 1] + 1;
        } else {
            l[i] = 2;
        }
    }
    
    r[n - 2] = 2;
    for (int i = n - 3; i >= 0; i--) {
        if (nums[i] - nums[i + 1] == nums[i + 1] - nums[i + 2]) {
            r[i] = r[i + 1] + 1;
        } else {
            r[i] = 2;
        }
    }

    ans = max({ans, l[1] + 1, r[n - 2] + 1});
    ans = max({ans, l[n - 2] + 1, r[1] + 1});

    for (int i = 1; i < n - 1; i++) {
        if ((nums[i- 1] - nums[i + 1]) % 2 == 0) {
            int d = (nums[i - 1] - nums[i + 1]) / 2;
            int left = (i > 1 && nums[i - 2] - nums[i - 1] == d) ? l[i - 1] : 1;
            int right = (i < n - 2 && nums[i + 1] - nums[i + 2] == d) ? r[i + 1] : 1;
            ans = max(ans, left + right + 1);
        }
        ans = max({ans, l[i - 1] + 1, r[i + 1] + 1});
    }

    return min(ans, n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}