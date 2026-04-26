#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countGoodIntegersOnPath(long long l, long long r, string directions) {
    using ll = long long;
    
    string low_s = to_string(l);
    string high_s = to_string(r);
    int n = high_s.size();
    int diff_lh = n - low_s.size();

    vector<int> digits = {0};
    for (int i = 0; i < 6; i++) {
        int res = digits[i] + (directions[i] == 'R' ? 1 : 4);
        digits.push_back(res);
    }

    vector memo(n, vector(10, -1));
    auto dfs = [&](this auto&& dfs, int i, bool limit_low, bool limit_high) -> int {
        if (i == n) {
            return 1;
        }

        if (!limit_low && !limit_high && memo[i][])
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}