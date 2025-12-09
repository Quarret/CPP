#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    // 对于每个左端点 l, 贪心的选择左端点在 l 上, 右端点更大的区间
    ranges::sort(queries, {}, [](auto &p) {
        return p[0];
    });
    
    int n = nums.size(), j = 0, sum_d = 0;
    vector<int> diff(n + 1, 0);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        sum_d += diff[i];

        while (j < queries.size() && queries[j][0] <= i) {
            pq.push(queries[j][1]);
            j++;
        }

        // 贪心选择右端点大的区间
        while (sum_d < nums[i] && !pq.empty() && pq.top() >= i) {
            diff[pq.top() + 1]--;
            pq.pop();
            sum_d++;
        }

        if (sum_d < nums[i]) {
            return -1;
        }
    }

    return pq.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
