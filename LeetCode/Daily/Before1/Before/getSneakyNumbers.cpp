#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> getSneakyNumbers(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<int> ans;
    
    for (int x : nums) {
        mp[x]++;
        if (mp[x] == 2) {
            ans.push_back(x);
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
