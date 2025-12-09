#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> findMissingElements(vector<int>& nums) {
    int minn = *min_element(nums.begin(), nums.end());       
    int maxx = *max_element(nums.begin(), nums.end());
    
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int x : nums) {
        mp[x] = 1;
    }

    for (int i = minn; i <= maxx; i++) {
        if (!mp[i]) {
            ans.push_back(i);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
