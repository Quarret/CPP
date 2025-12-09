#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countTriplets(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= j; i++) {
            int res = nums[j] & nums[i];
            
            for (int k = j; k < n; k++) {
                if (res & nums[k] == 0) ans++;
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
