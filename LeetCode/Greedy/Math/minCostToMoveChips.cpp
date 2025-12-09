#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minCostToMoveChips(vector<int>& position) {
    unordered_map<int, int> cnt;
    for (int x : position) {
        cnt[x]++;
    }

    int odd = 0, even = 0;
    for (auto [x, c] : cnt) {
        x % 2 ? odd : even += c;
    }

    return min(odd, even);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
