#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumCardPickup(vector<int>& cards) {
    int n = cards.size();
    unordered_map<int, int> mp;
    int ans = 1e9;
    
    for (int i = 0; i < n; i++) {
        if (mp[cards[i]]) {
            ans = min(ans, i + 1 - mp[cards[i]]);
        }
        mp[cards[i]] = i + 1;
    }

    return (ans == 1e9 ? -1 : ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
