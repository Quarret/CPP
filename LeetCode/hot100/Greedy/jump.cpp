#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int jump(vector<int>& nums) {
    int cur_right = 0, next_right = 0, ans = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
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
    cin.tie(nullptr);

    

    return 0;
}