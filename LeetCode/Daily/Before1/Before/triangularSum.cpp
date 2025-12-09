#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int triangularSum(vector<int>& nums) {
    int n = nums.size();
    vector f(n, vector<int>(n, 0));
    
    f[0] = nums;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            f[i][j] = (f[i - 1][j] + f[i - 1][j + 1]) % 10;
        }
    }

    return f[n][0];
}

// 原地算法
int triangularSum(vector<int>& nums) {
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            nums[j] = (nums[j] + nums[j + 1]) % 10;
        }
    }

    return nums[0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
