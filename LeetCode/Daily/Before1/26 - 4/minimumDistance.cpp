#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumDistance(vector<int>& nums) {
    int n = nums.size();
    
    int ans = INT_MAX;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] == nums[j] && nums[j] == nums[k]) {
                    ans = min(ans, j - i + k - i + k - j);
                }
            }
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}