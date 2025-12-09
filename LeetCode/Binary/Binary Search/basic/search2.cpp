#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {1,0,1,1,1};
bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = -1, r = n - 1, mid = 0;

    auto check = [&](int x) -> bool {
        if (nums[x] > nums[r]) return target > nums[r] && nums[x] >= target;
        return target > nums[r] || nums[x] >= target;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (nums[mid] == nums[r]) r--;
        else if (check(mid)) r = mid;
        else l = mid;
    }

    return nums[r] == target ? true : false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    search(nums, 0);

    return 0;
}
