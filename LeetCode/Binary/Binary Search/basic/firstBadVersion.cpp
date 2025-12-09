#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int firstBadVersion(int n) {
    int l = 0, r = n + 1, mid = 0;

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        //(isBadVersion(mid) ? r : l) = mid;
    }

    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
