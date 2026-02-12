#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> q;

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        // 1. 入 (保证单调性)
        while (!q.empty() && nums[q.back()] <= nums[i]) {
            q.pop_back();
        }
        q.push_back(i);

        // 2. 出
        while (!q.empty() && i - q.front() >= k) {
            q.pop_front();
        }

        if (i >= k - 1) {
            ans.push_back(nums[q.front()]);
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
