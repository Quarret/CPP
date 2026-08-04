#include <bits/stdc++.h>
using ll = long long;
using namespace std;


vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();
    
    unordered_map<int, vector<int>> idxs;
    for (int i = 0; i < n; i++) {
        idxs[nums[i]].push_back(i);
    }

    int m = queries.size();
    vector<int> ans(m, -1);
    for (int j = 0; j < m; j++) {
        
        int x = nums[queries[j]], q = queries[j];
        if (idxs[x].size() == 1) continue;
        int idx = ranges::lower_bound(idxs[x], q) - idxs[x].begin();
        
        int t = idxs[x].size();
        ans[j] = INT_MAX;
        if (idx != 0) ans[j] = min({ans[j], q - idxs[x][idx - 1], n - (q - idxs[x][idx - 1])});
        if (idx != t - 1) ans[j] = min({ans[j], idxs[x][idx + 1] - q, n - (idxs[x][idx] - q)});
        if (idx == 0) ans[j] = min({ans[j], idxs[x][idx + 1] - q, n - (idxs[x].back() - q)});
        if (idx == t - 1) ans[j] = min({ans[j], q - idxs[x][idx - 1], n - (q - idxs[x][0])});
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}