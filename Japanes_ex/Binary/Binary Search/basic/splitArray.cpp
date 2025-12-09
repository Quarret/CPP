#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
最小化最大值 也是一种二分答案---二分最大值
这种一般都是越大越符合题意，所以应该往r方向靠齐
(check(mid) ? r : l) = mid
*/
int splitArray(vector<int>& nums, int k) {
    int l = *max_element(nums.begin(), nums.end()) - 1;
    int r = 0, mid = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        r += nums[i];
    }
    r++;

    auto check = [&](int t) -> bool {
        int ans = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            /*
            错误写法
            不应该每次都检查是否到达k
            当sum <= t时跳过即可
            */
            sum += nums[i];

            if (ans == k) {
                cout << t << ' ' << i << '\n'; 
                return 0;
            }

            if (sum > t) {
                ans++;
                sum = nums[i];
            }

            //正确写法
            if (sum + nums[i] <= t) {
                sum += nums[i];
                continue;
            }

            if (ans == k) return 0;
            ans++;
            sum = nums[i];
        }

        return 1;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
