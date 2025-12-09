#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int n = capacity.size();
    for (int i = 0; i < n; i++) {
        capacity[i] -= rocks[i];
    }
    
    int ans = 0;
    sort(capacity.begin(), capacity.end());
    for (int i = 0; i < n && additionalRocks; i++) {
        if (additionalRocks >= capacity[i]) ans++;
        additionalRocks -= max(additionalRocks, capacity[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
