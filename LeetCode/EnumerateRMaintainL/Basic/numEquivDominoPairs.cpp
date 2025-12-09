#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int n = dominoes.size();
    unordered_map<int, int> mp;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int maxx = max(dominoes[i][0], dominoes[i][1]);
        int idx = (dominoes[i][0] + dominoes[i][1]) * (dominoes[i][0] + dominoes[i][1] + 1) / 2 + maxx;
        /*
        双映射函数,映射到唯一值
        f(x, y) = (x + y)(x + y + 1) / 2 + max(x, y)
        */

        ans += mp[idx];
        mp[idx]++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
