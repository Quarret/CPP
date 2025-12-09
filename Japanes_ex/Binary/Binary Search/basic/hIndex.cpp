#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {1, 2};
int hIndex(vector<int>& citations) {
    int l = -1, r = citations.size(), mid = 0, n = citations.size();

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (n - mid <= citations[mid]) r = mid;
        else l = mid;
    }

    return (r == n ? 0 : n - r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    hIndex(nums);

    return 0;
}
