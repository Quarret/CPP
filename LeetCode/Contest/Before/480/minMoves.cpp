#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minMoves(vector<int>& balance) {
    long long sum = reduce(balance.begin(), balance.end(), 0LL);
    if (sum < 0) return -1;
    
    int idx = -1, n = balance.size();
    for (int i = 0; i < n; i++) {
        if (balance[i] < 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return 0;

    int i = ((idx - 1) + n) % n, j = (idx + 1) % n;
    long long ans = 0, m = -balance[idx], k = 1;
    while (i != j && m) {
        ans += min(m, 1LL * (balance[i] + balance[j])) * k;
        m -= min(m, 1LL * (balance[i] + balance[j]));
        k++;
        i = ((i - 1) + n) % n;
        j = (j + 1) % n;
    }
    ans += min(m, 1LL * balance[i]) * k;

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
