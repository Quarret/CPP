#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mp;

    for (int x : nums) {
        pq.emplace(++mp[x], x);
    }

    vector<int> ans;
    while (k) {
        auto [c, x] = pq.top();
        pq.pop();
        if (mp[x] == c) {
            k--;
            ans.push_back(x);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
