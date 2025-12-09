#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {-3,-5,-3,-2,-6,3,10,-10,-8,-3,0,10,3,-5,8,7,-9,-9,5,-8};
int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    int minn = 1e9 + 5, maxx = -1e9 - 5, pre = nums[0];
    minn = min(minn, pre);
    maxx = max(maxx, pre);

    for (int i = 1; i < n; i++) {
        //cout << pre << ' ';
        pre = pre + nums[i];
        minn = min(minn, pre);
        maxx = max(maxx, pre);
    }
    //cout << pre << ' ';

    if (maxx > 0 && minn > 0) return maxx;
    else if (maxx < 0 && minn < 0) return -minn;
    else return maxx - minn;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maxAbsoluteSum(nums);

    return 0;
}
