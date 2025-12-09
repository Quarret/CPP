#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool kLengthApart(vector<int>& nums, int k) {
    int n = nums.size(), last1 = INT_MIN / 2;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) continue;
        if (i - last1 - 1 < k) return false;
        last1 = i;
    }
    
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
