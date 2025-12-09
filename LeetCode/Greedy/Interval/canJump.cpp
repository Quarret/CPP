#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool canJump(vector<int>& nums) {
    int cur_r = 0, next_r = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        next_r = max(next_r, i + nums[i]);

        if (i == cur_r) {
            if (cur_r == next_r) {
                return false;
            }
            cur_r = next_r;
        }
    }
    
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
