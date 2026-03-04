#include <bits/stdc++.h>
using ll = long long;
using namespace std;

char kthCharacter(long long k, vector<int>& operations) {
    int n = operations.size();
    auto dfs = [&](this auto&& dfs, int i, long long k) -> int {
        if (k == 1) {
            return 0;
        }

        if (i > 60) {
            return dfs(i - 1, k);
        }

        if (k <= (1LL << (i - 1))) {
            return dfs(i - 1, k);
        }

        return dfs(i - 1, k - (1LL << (i - 1))) + operations[i - 1];
    };

    return 'a' + (dfs(n, k) % 26);
}

// 迭代
char kthCharacter(long long k, vector<int>& operations) {
    int inc = 0;
    int m = __bit_width((uint64_t) k - 1);
    for (int i = m - 1; i >= 0; i--) {
        if (k > (1LL << i)) {
            inc += operations[i];
            k -= 1LL << i;
        }
    }

    return 'a' + (inc % 26);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}