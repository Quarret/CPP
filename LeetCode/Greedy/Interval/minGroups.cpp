#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minGroups(vector<vector<int>>& intervals) {
    ranges::sort(intervals, {}, [](auto &p) {
        return p[1];
    });
    
    priority_queue<int, vector<int>, greater<>> pq;
    for (auto &p : intervals) {
        int l = p[0], r = p[1];
        if (!pq.empty() && pq.top() < l) pq.pop();
        pq.push(r);
    }

    return pq.size();
}

// 上下车模型 在 l 上车, 在 r + 1 下车
// 差分计算公式: 对区间[l, r] 区间加一 = diff[l] + 1,  diff[r + 1] - 1
// diff[i] 表示对 [i, n - 1] 上数字进行操作  
// 最少区间数就是在车上最多人数
int minGroups(vector<vector<int>>& intervals) {
    map<int, int> diff;

    for (auto &p : intervals) {
        diff[p[0]]++;
        diff[p[1] + 1]--;
    }

    int ans = 0, sum = 0;
    for (auto &[_, c] : diff) {
        ans = max(ans, sum += c);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
