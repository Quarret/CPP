#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {1,1,2,3,3,4,4,8,8};
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = -1, r = n, mid = 0;

    if (n == 1) return nums[0];

    auto check = [&](int x) -> bool {
        int num = n - x - 1;
        if (nums[x] == nums[x + 1]) num++;
        return num % 2 == 0;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return (r == n ? nums.back() : nums[r]);
}

/*
灵神写法:找到mid值与目标数之间的关系
目标书一定出现在偶数下标上，
当目标数出现在2 * mid之外时, 2 * mid 与 2 * mid + 1的值相等
当目标数出现在2 * mid之内时，其中的2 * mid 与 2 * mid + 1的值就会往后移而不等
所以我们可以得出，当mid越大，满足2 * mid 与 2 * mid + 1不等越满足，具有单调性
*/

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = -1, r = n / 2, mid = 0;

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (nums[2 * mid] != nums[2 * mid + 1] ? r : l) = mid;
    }

    return nums[r];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    singleNonDuplicate(nums);

    return 0;
}
