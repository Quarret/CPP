#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 特殊化, 假设只有两个元素
long long minDamage(int power, vector<int>& damage, vector<int>& health) {
    int n = damage.size();
    vector<int> idx(n);
    ranges::iota(idx, 0);    
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        int tx = (health[x] + power - 1) / power;
        int ty = (health[y] + power - 1) / power;
        return 1LL * damage[y] * tx < 1LL * damage[x] * ty;
    });

    long long pre = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        pre += (health[idx[i]] + power - 1) / power;
        ans += 1LL * pre * damage[idx[i]];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
