#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    auto qpow = [&](int x, int n, int MOD) -> int {
        int ans = 1;
        while (n) {
            if (n & 1) {
                ans = (ans * x) % MOD;
            }

            n >>= 1;
            x = (x * x) % MOD;
        }

        return ans;
    };
    
    vector<int> ans;
    for (int i = 0; i < variables.size(); i++) {
        auto v = variables[i];
        int a = v[0], b = v[1], c = v[2], m = v[3];
        if (qpow(qpow(a, b, 10), c, m) == target) ans.push_back(i);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
