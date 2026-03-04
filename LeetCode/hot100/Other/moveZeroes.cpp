#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
以 x 来记录非0元素
遇到非0元素swap(num[x], num[i])

O(n)

*/
vector<int> nums;
void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                swap(nums[i], nums[x++]);
            }
        }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tmp;
    while (cin >> tmp) {
        nums.push_back(tmp);
    }

    return 0;
}
