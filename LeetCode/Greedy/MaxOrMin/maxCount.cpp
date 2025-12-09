#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxCount(vector<int>& banned, int n, int maxSum) {
    unordered_map<int, int> mp;
    for (int x : banned) {
        mp[x] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[i]) continue;
        if (maxSum < i) break;
        ans++;
        maxSum -= i;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
