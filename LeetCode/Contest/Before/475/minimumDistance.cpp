#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumDistance(vector<int>& nums) {
    int n = nums.size();
    
    int ans = INT32_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] == nums[j] && nums[j] == nums[k]) {
                    ans = min(ans, j - i + k - j + k - i);
                }
            }
        }
    }

    return ans == INT32_MAX ? -1 : ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
