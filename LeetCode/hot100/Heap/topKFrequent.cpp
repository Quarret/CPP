#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for (int x : nums) {
        cnt[x]++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;
    for (auto &[x, c] : cnt) {
        pq.emplace(c, x);
    }

    vector<int> ans;
    for (int i = 0; i < k && !pq.empty(); i++) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;        
}

// 桶排序
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    int mx = 0;
    for (int x : nums) {
        cnt[x]++;
        mx = max(mx, cnt[x]);
    }

    vector<vector<int>> buckets(mx + 1);
    for (auto &[x, c] : cnt) {
        buckets[c].push_back(x);
    }

    vector<int> ans;
    for (int i = mx; i >= 0 && ans.size() < k; i--) {
        ans.insert(ans.begin(), buckets[i].begin(), buckets[i].end());
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}