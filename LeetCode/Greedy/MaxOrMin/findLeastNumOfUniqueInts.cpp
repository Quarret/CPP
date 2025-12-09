#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    int cnt = 0;
    unordered_map<int, int> mp;
    vector<int> nums;

    for (int x : arr) {
        if (!mp[x]) {
            cnt++;
            nums.push_back(x);
        }
        mp[x]++;
    }

    sort(nums.begin(), nums.end(), [&](int a, int b) {
        return mp[a] < mp[b];
    });

    for (int x : nums) {
        if (k < mp[x]) break;
        k -= mp[x];
        cnt--;
    }

    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
