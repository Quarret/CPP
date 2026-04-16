#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int getMinDistance(vector<int>& nums, int target, int start) {
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            ans = min(ans, abs(i - start));
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}