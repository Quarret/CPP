#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 交换座位
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
            int j = nums[i] - 1;
            swap(nums[i], nums[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        } 
    }

    return n + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}