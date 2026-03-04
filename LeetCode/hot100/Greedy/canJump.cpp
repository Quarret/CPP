#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool canJump(vector<int>& nums) {
    int cur_i = 0, next_i = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        next_i = max(next_i, i + nums[i]);

        if (i == cur_i) {
            if (cur_i == next_i) return false;
            cur_i = next_i;
        }
    }
    
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}