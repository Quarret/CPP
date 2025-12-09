#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> findLongestSubarray(vector<string>& array) {
    int n = array.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (array[i][0] >= '0' && array[i][0] <= '9') pre[i + 1] = pre[i] + 1;
        else pre[i + 1] = pre[i];
    }

    unordered_map<int, int> mp;
    mp[0] = 0;
    int res = 0, idx = 0;
    for (int j = 1; j <= n; j++) {
        int cur = 2 * pre[j] - j;
        if (mp.contains(cur)) {
            if (j - mp[cur] > res) {
                res = j - mp[cur];
                idx = mp[cur];
            }
        } else mp[cur] = j;
    }

    vector<string> ans;
    if (res == 0) return ans;
    
    // for (int i = idx; i <= idx + res - 1; i++) {
    //     ans.push_back(array[i]);
    // }
    //return ans;
    return {array.begin() + idx, array.begin() + idx + res};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
