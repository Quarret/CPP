#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long minimumMoney(vector<vector<int>>& transactions) {
    long long sum = 0;
    for (auto &e : transactions) {
        int cost = e[0], back = e[1];
        sum += max(cost - back, 0);
    }

    long long ans = 0;
    for (auto &e : transactions) {
        long long diff = max(0, e[0] - e[1]);
        ans = max(ans, 1LL * e[0] + sum - diff);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
