#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
滑动窗口题，找寻定量滑动窗口长度 L 是解题关键
*/
int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    vector<long long> nums;
    int n = startTime.size();

    nums.push_back(startTime[0] - 0);
    for (int i = 1; i < n; i++) {
        nums.push_back(startTime[i] - endTime[i - 1]);
    }
    nums.push_back(eventTime - endTime[n - 1]);
    
    long long ans = 0, num = 0, m = nums.size();
    for (int i = 0; i < m; i++) {
        num += nums[i];

        if (i < k) continue;

        ans = max(ans, num);
        num -= nums[i - k];
    }

    return ans;
}

/*
优化创建空闲时间数组写法，优化1个 O(n) 时间以及 O(n) 内存
*/

int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();

    auto get = [&](int i) -> int {
        if (i == 0) return startTime[0];
        else if (i == n) return eventTime - endTime[n - 1];
        return startTime[i] - endTime[i - 1];
    };
    
    long long ans = 0, num = 0;
    for (int i = 0; i <= n; i++) {
        num += get(i);

        if (i < k) continue;

        ans = max(ans, num);
        num -= get(i - k);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
