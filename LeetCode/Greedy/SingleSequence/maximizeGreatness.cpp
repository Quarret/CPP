#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maximizeGreatness(vector<int>& nums) {
    int ans = 0, n = nums.size();
    sort(nums.begin(), nums.end(), greater());
    
    int i = 0, j = 0;
    while (1) {
        while (j < n && nums[i] == nums[j]) {
            j++;
        }
        if (j == n) {
            break;
        } else {
            ans++;
            i++;
            j++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
