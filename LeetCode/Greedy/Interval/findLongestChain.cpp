#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {
    ranges::sort(pairs, {}, [](auto &a) {
        return a[1];
    });

    int ans = 0, right = INT_MIN;
    for (auto &p : pairs) {
        if (p[0] > right) {
            right = p[1];
            ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
