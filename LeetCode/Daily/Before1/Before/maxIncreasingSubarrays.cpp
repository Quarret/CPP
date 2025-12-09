#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxIncreasingSubarrays(vector<int>& nums) {
    int n = nums.size();
    int ans = 0, cnt = 0, pre = 0;
    
    for (int i = 0; i < n; i++) {
        cnt++; // 当前递增数列长度

        // i 为递增数组末尾
        if (i == n - 1 || nums[i] >= nums[i + 1]) {
            // 直接分当前cnt
            // pre做左一段, cnt做右一段 (双指针) 
            ans = max({ans, cnt / 2, min(pre, cnt)});
            pre = cnt;
            cnt = 0; // 此处不递增, 重新开始
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
