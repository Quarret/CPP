#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> minBitwiseArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        if (nums[i] == 2) {
            ans[i] = -1;
            continue;
        }

        int len = 0;
        while (nums[i] & (1 << (len + 1))) len++;
        ans[i] = nums[i] - (1 << len);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
