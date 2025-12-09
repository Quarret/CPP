#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimizedMaximum(int n, vector<int>& quantities) {
    int m = quantities.size();
    int l = -1, r = *max_element(quantities.begin(), quantities.end()), mid = 0;

    auto check = [&](int k) -> bool {
        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans += (quantities[i] + k - 1) / k;

            return ans == n;
        }
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
