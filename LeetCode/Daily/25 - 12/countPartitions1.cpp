#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countPartitions(vector<int>& nums, int k) {
    int n = nums.size();
    const int MOD = 1e9 + 7;
    vector<int> memo(n, -1);
    
    auto dfs = [&](this auto&& dfs, int i) -> int {
        if (i == n) {
            return 1;
        }

        int &res = memo[i];
        if (res != -1) return res;

        res = 0;
        int maxx = INT_MIN, minn = INT_MAX;
        for (int j = i; j < n; j++) {
            maxx = max(maxx, nums[j]);
            minn = min(minn, nums[j]);
            if (maxx - minn > k) break;
            res = (res + dfs(j + 1)) % MOD;
        }

        return res;
    };

    return dfs(0) % MOD;
}

// 单调队列 + 划分型 DP
int countPartitions(vector<int>& nums, int k) {
    int n = nums.size();
    const int MOD = 1e9 + 7;

    // 单调队列维护窗口最大值最小值
    deque<int> min_q, max_q;
    
    // f[i + 1] 表示 [0, i] 上的合法分割方案数
    vector<int> f(n + 1);
    long long sum_f = 0;
    f[0] = 1;
    int left = 0;

    for (int i = 0; i < n; i++) {
        int x = nums[i];
        // 入
        sum_f += f[i];

        while (!min_q.empty() && nums[min_q.back()] >= x) {
            min_q.pop_back();
        }
        min_q.push_back(i);

        while (!max_q.empty() && nums[max_q.back()] <= x) {
            max_q.pop_back();
        }
        max_q.push_back(i);

        // 出
        while (nums[max_q.front()] - nums[min_q.front()] > k) {
            sum_f -= f[left];
            left++;
            if (max_q.front() < left) {
                max_q.pop_front();
            }
            if (min_q.front() < left) {
                min_q.pop_front();
            }
        }

        // 更新
        f[i + 1] = sum_f % MOD;
    }

    return f[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
