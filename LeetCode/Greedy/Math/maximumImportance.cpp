#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> cnt(n, 0);
    
    for (auto &road : roads) {
        cnt[road[0]]++;
        cnt[road[1]]++;
    }

    long long ans = 0;
    ranges::sort(cnt);
    for (int i = 0; i < n; i++) {
        ans += 1LL * cnt[i] * (i + 1);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
