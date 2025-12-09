#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumCost(vector<int>& cost) {
    int ans = 0, n = cost.size();
    for (int x : cost) ans += x;
    sort(cost.begin(), cost.end(), greater());
    
    for (int i = 2; i < n; i += 3) {
        ans -= cost[i];
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
