#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int MX = 1'000'001;
int LPF[MX];
auto init = [] {
    LPF[1] = 1;
    for (int i = 2; i < MX; i++) {
        if (LPF[i] != 0) continue;
        for (int j = i; j < MX; j += i) {
            if (LPF[j] == 0) {
                LPF[j] = i;
            }
        }            
    }

    return 0;
}();


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = n - 1; i >= 1; i--) {
            if (nums[i - 1] > nums[i]) {
                nums[i - 1] = LPF[nums[i - 1]];
                if (nums[i - 1] > nums[i]) {
                    return -1;
                }
                ans++;
            }
        }

        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
