#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countSubarrays(vector<int>& nums, long long k) {
    using ll = long long;
    deque<int> min_q, max_q;

    ll ans = 0;
    for (int r = 0, l = 0; r < nums.size(); r++) {
        while (!min_q.empty() && nums[min_q.back()] >= nums[r]) min_q.pop_back();
        min_q.push_back(r);

        while (!max_q.empty() && nums[max_q.back()] <= nums[r]) max_q.pop_back();
        max_q.push_back(r);

        while (l <= r && 1LL * (nums[max_q.front()] - nums[min_q.front()]) * (r - l + 1) > k) {
            l++;

            if (max_q.front() < l) max_q.pop_front();
            if (min_q.front() < l) min_q.pop_front();
        }

        ans += r - l + 1;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}