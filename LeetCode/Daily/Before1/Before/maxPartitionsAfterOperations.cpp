#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxPartitionsAfterOperations(string s, int k) {
    unordered_map<long long, int> memo;
    auto dfs = [&](this auto&& dfs, int i, int mask, int changed) -> int {
        if (i == s.size()) return 1;

        // 将所有状态压缩到一个 long long 中, 方便 memo 数组记录
        long long args = (1LL * i << 32) | (mask << 1) | changed;
        auto it = memo.find(args);
        if (it != memo.end()) {
            return it->second;
        }

        int res = 0;

        // 不改 s[i]
        int bit = 1 << (s[i] - 'a');
        int new_mask = mask | bit;
        if (__builtin_popcount((uint32_t)new_mask) > k) {
            // 分割
            res = dfs(i + 1, bit, changed) + 1;
        } else {
            // 不分割
            res = dfs(i + 1, new_mask, changed);
        }

        // 改 s[i]
        if (!changed) {
            // 枚举 s[i] 修改为 a, b, c...
            for (int j = 0; j < 26; j++) {
                int new_mask = mask | (1 << j);
                if (__builtin_popcount((uint32_t)new_mask) > k) {
                    res = max(dfs(i + 1, 1 << j, 1) + 1, res);
                } else {
                    res = max(dfs(i + 1, new_mask, 1), res);
                }
            }
        }
        
        memo[args] = res;
        return res;
    };

    return dfs(0, 0, false);
}

int maxPartitionsAfterOperations(string s, int k) {
    if (k == 25) return 1;
    
    int seg = 1, size = 0, mask = 0;
    auto update = [&](int i) -> void {
        int bit = 1 << (s[i] - 'a');
        if (mask & bit) { // s[i] 已经在集合中
            return;
        }
        if (++size > k) { // 分段 
            seg++;
            mask = bit;
            size = 1;
        } else {
            mask |= bit;
        }
    };

    int n = s.size();
    // 统计逆序不同 i 的 {段数, 集合}
    vector<pair<int, int>> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        update(i);
        suf[i] = {seg, mask};
    }

    int ans = seg; // 不修改任何字母
    seg = 1, mask = 0, size = 0;
    for (int i = 0; i < n; i++) {
        auto [suf_seg, suf_mask] = suf[i + 1];
        int res = seg + suf_seg; // 情况 3
        int union_mask = __builtin_popcount(mask | suf_mask);
        if (union_mask < k) { // 情况 1 
            res--;
        } else if (union_mask < 26 && size == k && __builtin_popcount(suf_mask) == k) { // 情况 2
            res++;
        }

        ans = max(res, ans);
        update(i);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
