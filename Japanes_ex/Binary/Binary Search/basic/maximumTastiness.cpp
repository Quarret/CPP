#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> prices = {1, 2, 5, 8, 13, 21};
int maximumTastiness(vector<int>& price, int k) {
    int n = price.size();
    sort(price.begin(), price.end());
    long long l = -1, r = price.back() - price[0] + 1, mid = 0;

    auto check = [&](long long t) -> bool {
        long long num = price[0] + t, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (price[i] >= num) {
                cnt++;
                num = prices[i] + t;
            }

            if (cnt >= k) return 1;
        }
        return 0;
        
        int l1 = -1;
        for (int i = 0; i < k - 1; i++) {
            int r1 = n, mid1 = 0;

            while (l1 + 1 < r1) {
                mid1 = l1 + (r1 - l1) / 2;
                if (price[mid1] < num) l1 = mid1;
                else r1 = mid1;
            }

            if (r1 == n) return 0;
            num = price[r1] + t;
               l1 = r1;
        }
        return 1;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << maximumTastiness(prices, 3);

    return 0;
}
