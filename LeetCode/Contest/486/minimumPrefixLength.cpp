#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumPrefixLength(vector<int>& nums) {
    int n = nums.size();
    
    int pre = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] >= pre) return i + 1;
        pre = nums[i];
    }

    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}