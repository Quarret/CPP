#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxDistance(vector<int>& position, int m) {
    int n = position.size();
    sort(position.begin(), position.end());
    long long l = 0, r = position.back() - position[0] + 1, mid = 0;

    auto check = [&](long long k) -> bool {
        int cnt = 1, num = position[0];
        for (int i = 1; i < n; i++) {
            if (position[i] - num >= k) {
                cnt++;
                num = position[i];
            }

            if (cnt == k) return 1;
        }

        return 0;
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

    

    return 0;
}
