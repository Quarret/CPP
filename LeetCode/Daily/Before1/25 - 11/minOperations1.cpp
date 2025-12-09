#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minOperations(vector<int>& nums) {
    int n = nums.size();
    int ok = nums[0], cnt = 0;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) cnt++;
        ok = gcd(ok, nums[i]);
    }

    if (ok != 1) return -1;
    if (cnt) return n - cnt;

    int minn = INT_MAX;
    for (int i = 0; i < n; i++) {
        int g = nums[i];
        for (int j = i; j < n; j++) {
            g = gcd(g, nums[j]);
                
            if (g == 1) {
                minn = min(minn, j - i);
                break;
            }
        }
    }

    return n + minn - 1;
}

int minOperations(vector<int>& nums) {
    int n = nums.size(), gcd_all = 0, cnt = 0;
    for (int x : nums) {
        gcd_all = gcd(gcd_all, x);
        cnt += x == 1;
    }
    
    if (gcd_all != 1) return -1;
    if (cnt) return n - cnt;

    int min_size = n;
    // <gcd, idx> 从小到大排列
    map<int, int> pre_gcds;
    for (int i = 0; i < n; i++) {
        // 以当前 nums[i] 为右端点开始的左侧 gcds
        map<int, int> cur_gcds;
        cur_gcds[nums[i]] = 1;

        for (auto &[g, size] : pre_gcds) {
            int new_g = gcd(g, nums[i]), new_sz = size + 1;
            if (cur_gcds.contains(new_g)) {
                cur_gcds[new_g] = min(cur_gcds[new_g], new_sz);
            } else {
                cur_gcds[new_g] = new_sz;
            }
        }

        pre_gcds = cur_gcds;
        if (pre_gcds.count(1)) {
            min_size = min(min_size, pre_gcds[1]);
        }
    }

    return n + min_size - 2;
}

int minOperations(vector<int>& nums) {
    int n = nums.size(), gcd_all = 0, cnt = 0;
    for (int x : nums) {
        gcd_all = gcd(gcd_all, x);
        cnt += x == 1;
    }
    
    if (gcd_all != 1) return -1;
    if (cnt) return n - cnt;

    int min_size = n;
    for (int i = 0; i < n; i++) {
        int g = nums[i];
        for (int j = i - 1; j >= 0; j--) {
            int &y = nums[j], g = gcd(g, y);
            if (g == y) {
                break;
            }
            y = g;

            if (g == 1) {
                min_size = min(min_size, i - j);
            }
        }
    }

    return n + min_size - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
