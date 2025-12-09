#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end());
    int n = piles.size() / 3;
    
    long long ans = 0;
    for (int i = n; i < piles.size(); i += 2) {
        ans += 1LL * piles[i];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
