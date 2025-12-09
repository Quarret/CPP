#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int check(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
int searchInsert(vector<int>& nums, int target) {
        return check(nums, target);

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
