#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = {nums2[i], i};
    }
    sort(a.begin(), a.end());

    sort(nums1.begin(), nums1.end());
    vector<int> ans(n, -1), unvisited;
    int j = 0;
    for (int i = 0; i < n; i++) {
        auto [x, idx] = a[i];
        while (j < n && nums1[j] <= x) {
            unvisited.push_back(j);
            j++;
        }
        if (j != n) {
            ans[idx] = nums1[j++];
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            ans[i] = nums1[unvisited.back()];
            unvisited.pop_back();
        }
    }
    
    return ans;
}

// 涉及到下标, 创建下标数组
vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    ranges::sort(nums1);
    
    int n = nums1.size();
    vector<int> idx(n);
    ranges::iota(idx, 0);
    ranges::sort(idx, {}, [&](int i) {
        return nums2[i];
    });

    vector<int> ans(n);
    int left = 0, right = n - 1;
    for (int x : nums1) {
        // 若能够匹配, 匹配与自己最近的; 若不能匹配, 匹配最大的, 减小后续匹配压力 
        int i = x > nums2[idx[left]] ? idx[left++] : idx[right--];
        ans[i] = x;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
