#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int jump(vector<int>& nums) {
    int ans = 0, n = nums.size();
    int cur_right = 0; // 当前已有桥的右端点
    int next_right = 0; // 在已有桥基础上可以走到的最大右端点        

    for (int i = 0; i + 1 < n; i++) {
        next_right = max(next_right, i + nums[i]);
        if (i == cur_right) {
            ans++;
            cur_right = next_right;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
