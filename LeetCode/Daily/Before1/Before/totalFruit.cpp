#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    unordered_map<int, int> mp;
    int cnt = 0;
    
    int ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        if (!mp[fruits[r]]) cnt++;
        mp[fruits[r]]++;

        while (cnt > 2) {
            mp[fruits[l]]--;
            if (!mp[fruits[l]]) cnt--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
