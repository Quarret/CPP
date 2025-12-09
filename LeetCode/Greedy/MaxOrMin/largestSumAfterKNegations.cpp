#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    
    int sum = 0, maxx = INT32_MAX / 4, minn = INT32_MAX / 4;
    for (int x : nums) {
        if (x <= 0) {
            if (k > 0) {
                k--;
                x = -x;
            }
            maxx = min(maxx, x);
        } else {
            minn = min(minn, x);
        }
        sum += x;
    }

    if (k == 0) return sum;
    else {
        return k % 2 ? sum - 2 * min(maxx, minn) : sum;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
