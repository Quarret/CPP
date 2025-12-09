/*** 
 * @Author: Quarret
 * @Date: 2025-06-07 19:47:57
 * @LastEditTime: 2025-06-07 20:07:38
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, pair<int, long long>> mp;
    for (int i = 0; i < n; i++) {
        mp[nums[i]].first++;
        mp[nums[i]].second += i;
    }

    vector<long long> arr;
    unordered_map<int, pair<int, long long>> pre;//<cnt, pre>>

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        pre[num].first++;
        pre[num].second += i;
        arr.push_back(1LL * i * pre[num].first - pre[num].second + mp[num].second - pre[num].second - 1LL * (mp[num].first - pre[num].first) * i);
    }

    return arr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
