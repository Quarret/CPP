#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

class NumArray {
private:
    vector<int> nums;
    // 树状数组
    vector<int> tree;

    int prefixSum(int i) {
        int s = 0;
        while (i) {
            s += tree[i];
            i -= i & -i; // i 减去 lowbit
        }
        return s;
    }

public:
    NumArray(vector<int> &nums) : nums(nums.size()), tree(nums.size() + 1)
    {
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        for (int i = index + 1; i < tree.size(); i += i & -i) {
            tree[i] += delta;
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
