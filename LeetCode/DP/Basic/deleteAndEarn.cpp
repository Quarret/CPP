#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    int maxx = *max_element(nums.begin(), nums.end());
    vector<int> val(maxx + 1);

    for (int x : nums) val[x] += x;
    int n = val.size();
    vector<int> f(n + 2);
    for (int i = 0; i < n; i++) {
        f[i + 2] = max(f[i + 1], f[i] + val[i]);
    }

    return f[n + 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
