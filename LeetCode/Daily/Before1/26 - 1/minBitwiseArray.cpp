#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> minBitwiseArray(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        int res = -1;
        if (mp.contains(x)) {
            ans[i] = mp[x];
            continue;
        }

        for (int y = 0; y <= x; y++) {
            if ((y | (y + 1)) == x) {
                res = y;
                break;
            }
        }
        ans[i] = res;
        mp[x] = res;
    }

    return ans;
}

// 最大连续 1 的最高位
// lowbit(x) = x & -x`
vector<int> minBitwiseArray(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        if (x == 2) {
            ans[i] = -1;
        } else {
            int t = ~x;
            ans[i] = x ^ ((t & -t) >> 1);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}