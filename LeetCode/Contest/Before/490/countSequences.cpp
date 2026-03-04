#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countSequences(vector<int>& nums, long long k) {
    using ll = long long;
    map<tuple<int, ll, ll>, int> memo;
    
    // 状态定义: 到达第 i 个数时, 被除数为 p, 除数为 q
    auto dfs = [&](this auto&& dfs, int i, ll p, ll q) -> int {
        if (i < 0) {
            return p % q == 0 && p / q == k;
        }

        auto t = tuple(i, p, q);
        auto it = memo.find(t);
        if (it != memo.end()) {
            return it->second;
        }

        // val * nums[i]
        int g = gcd(p * nums[i], q);
        int res1 = dfs(i - 1, p * nums[i] / g, q / g);
        // 约分缩小搜索范围

        // val / nums[i]
        g =  gcd(p, q * nums[i]);
        int res2 = dfs(i - 1, p, q * nums[i]);
        
        // val 不变 
        int res3 = dfs(i - 1, p, q); 
        
        int res = res1 + res2 + res3;

        memo[t] = res;
        return res;
    };

    return dfs(nums.size() - 1, 1LL, 1LL);
}

// 质因数分解
// 将 nums[i] 分解为 (e2, e3, e5) 的向量组, 将搜索空间限制在质因数组合内, 记忆化效率高

class Solution {
    // 返回 k 中的 2, 3, 5 因数的个数, 并且判断是否只包含 <= 5 的质因数
    pair<tuple<int, int, int>, bool> primeFactorization(long long k) {
        int e2 = countr_zero((uint64_t) k);
        k >>= e2;

        int e3 = 0;
        while (k % 3 == 0) {
            e3++;
            k /= 3;
        }

        int e5 = 0;
        while (k % 5 == 0) {
            e5++;
            k /= 5;
        }

        return {tuple(e2, e3, e5), k == 1};
    }

public:
    int countSequences(vector<int>& nums, long long k) {
        auto [e, ok] = primeFactorization(k);
        if (!ok) return 0;

        int n = nums.size();
        vector<tuple<int, int, int>> es(n);
        for (int i = 0; i < n; i++) {
            es[i] = primeFactorization(nums[i]).first;
        }

        unordered_map<int, int> memo;
        auto dfs = [&](this auto&& dfs, int i, int e2, int e3, int e5) -> int {
            if (i < 0) {
                return e2 == 0 && e3 == 0 && e5 == 0;
            }

            // k 最大为 10e15 = 2^50, 每个质因数最多为 6 或 7 位
            int mask = (i << 21) | ((e2 + 2 * n) << 14) | ((e3 + n) << 7) | (e5 + n);
            auto it = memo.find(mask);
            if (it != memo.end()) {
                return it->second;
            }

            auto [x, y, z] = es[i];
            int res1 = dfs(i - 1, e2 + x, e3 + y, e5 + z);
            int res2 = dfs(i - 1, e2 - x, e3 - y, e5 - z);
            int res3 = dfs(i - 1, e2, e3, e5);
            int res = res1 + res2 + res3;

            memo[mask] = res;
            return res;
        };

        auto [e2, e3, e5] = e;
        return dfs(n - 1, e2, e3, e5);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}