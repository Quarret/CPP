#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int check(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int mid;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
int search(vector<int>& nums, int target) {
    int num1 = check(nums, target);
    
    if (num1 == nums.size() || nums[num1] != target) return -1;
    return num1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
