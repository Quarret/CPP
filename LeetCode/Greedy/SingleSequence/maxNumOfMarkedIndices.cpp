#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxNumOfMarkedIndices(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    int i = 0;
    for (int j = (n + 1) / 2; j < n; j++) {
        if (nums[j] >= 2 * nums[i]) {
            i++;
        }
    }

    return i * 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
