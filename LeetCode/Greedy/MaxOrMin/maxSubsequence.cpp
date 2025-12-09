#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> maxSubsequence(vector<int>& nums, int k) {
    int n = nums.size();
    
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        a.emplace_back(nums[i], i);
    }
    sort(a.begin(), a.end(), greater());

    vector<pair<int, int>> b;
    for (int i = 0; i < k; i++) {
        b.push_back(a[i]);
    }

    sort(b.begin(), b.end(), [&](pair<int, int> &x, pair<int, int> &y) {
        return x.second < y.second;
    });

    vector<int> ans;
    for (auto [x, _] : b) {
        ans.push_back(x);
    }
    return ans;
}

vector<int> maxSubsequence(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> idx(n);

    // 从 0 开始连续赋值
    ranges::iota(idx, 0);
    ranges::sort(idx, {}, [&](int i) {
        return -nums[i];
    });

    idx.resize(k);
    ranges::sort(idx);

    for (int &i : idx) {
        i = nums[i];
    }
    return idx;
}

vector<int> maxSubsequence(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> idx(n);

    // 从 0 开始连续赋值
    ranges::iota(idx, 0);
    ranges::nth_element(idx, idx.begin(), {}, [&](int i) {
        return -nums[i];
    });

    vector<bool> in_seq(n);
    for (int i = 0; i < k; i++) {
        in_seq[idx[i]] = true;
    }

    idx.resize(k);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (in_seq[i]) {
            idx[j++] = nums[i];
        }
    }

    return idx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
