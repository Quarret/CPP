#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {7,40,10,10,40,39,96,21,54,73,33,17,2,72,5,76,28,73,59,22,100,91,80,66,5,49,26,45,13,27,74,87,56,76,25,64,14,86,50,38,65,64,3,42,79,52,37,3,21,26,42,73,18,44,55,28,35,87};
long long continuousSubarrays(vector<int>& nums) {
    long long n = nums.size(), l = 0, ans = 0, num = 0, maxx = -1, minn = 1e9, r1 = 0;
    
    for (int r = 0; r < n; r++) {
        maxx = max(maxx, (long long)nums[r]);
        minn = min(minn, (long long)nums[r]);

        r1 = r;
        if (abs(maxx - nums[r]) > 2 || abs(minn - nums[r]) > 2) {
            maxx = -1, minn = 1e9;
            while (abs(nums[r1] - nums[r]) <= 2) {
                maxx = max(maxx, (long long)nums[r1]);
                minn = min(minn, (long long)nums[r1]);
                r1--;
            }
        }

        l = (r1 == r ? l : r1 + 1);
        ans += r - l + 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << continuousSubarrays(nums);

    return 0;
}
