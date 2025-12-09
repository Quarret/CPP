#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
    int n = houses.size(), m = heaters.size(), l = 0, r = -1, mid = 0;
    int numl, numr, num1, num2, pos1, pos2;

    int maxhouse = -1, minhouse = 1e9;
    int maxheater = -1, minheater = 1e9;
    for (int i = 0; i < n; i++) {
        maxhouse = max(maxhouse, houses[i]);
        minhouse = min(minhouse, houses[i]);
    }
    for (int i = 0; i < m; i++) {
        maxheater = max(maxheater, heaters[i]);
        minheater = min(minheater, heaters[i]);
    }
    r = max(maxhouse - minheater, maxheater - minhouse);
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    auto check2 = [&](int t) -> int {
        int l1 = 0, r1 = n - 1, mid1 = 0;
        while (l1 <= r1) {
            mid1 = l1 + (r1 - l1) / 2;
            if (houses[mid1] < t) l1 = mid1 + 1;
            else r1 = mid1 - 1;
        }

        return l1;
    };

    auto check = [&](int k) -> bool {
        numl = heaters[0] - k;
        if (numl > minhouse) return 0;

        for (int i = 1; i < m; i++) {
            num1 = heaters[i - 1] + k + 1;
            num2 = heaters[i] - k - 1;

            if (num2 - num1 > 1) {
                pos1 = check2(num1);
                pos2 = check2(num2 + 1) - 1;
                if (pos2 - pos1 + 1 != 0) return 0;
            }
        }

        numr = heaters.back() + k;
        if (numr < maxhouse) return 0;

        return 1;
    };

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (!check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
