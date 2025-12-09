#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    long long l = 1, r = -1, n = piles.size(), mid = 0;
    for (int i = 0; i < n; i++) r = max(r, (long long)piles[i]);
    
    auto check = [&](long long k) -> long long{
        long long ans = 0;
        for (int i = 0; i < n; i++) ans += (piles[i] + k - 1) / k;

        return ans;
    };

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(mid) > h) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
