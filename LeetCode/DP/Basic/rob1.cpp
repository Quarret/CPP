#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    auto rob1 = [&](int start, int end) -> int {
        vector<int> f(n + 2);
        
        for (int i = start; i < end; i++) {
            f[i + 2] = max(f[i + 1], f[i] + nums[i]);
        }

        return f[end + 1];
    };
    
    return max(nums[0] + rob1(2, n - 1), rob1(1, n));//nums[0] only pick or not
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
