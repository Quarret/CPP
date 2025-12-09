#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxPossibleScore(vector<int>& start, int d) {
    int n = start.size();
    sort(start.begin(), start.end());
    long long l = start[1] - start[0] - 1, r = start.back() + d - start[0], mid = 0;
    
    auto check = [&](long long k) -> bool {
        long long num = start[0];
        for (int i = 1; i < n; i++) {
            if (num + k > start[i] + d) return 0;
            num = max(num + k, (long long)start[i]);
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

    

    return 0;
}
