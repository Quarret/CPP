#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minSetSize(vector<int>& arr) {
    unordered_map<int, int> mp;
    for (int x : arr) {
        mp[x]++;
    }
    
    int sum = 0;
    vector<int> nums;
    for (auto [_, c] : mp) {
        nums.push_back(c);
        sum += c;
    }
    sort(nums.begin(), nums.end(), greater());

    int ans = 0, pre = 0;
    for (int x : nums) {
        pre += x;
        ans++;
        if (2 * pre >= sum) {
            break;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
