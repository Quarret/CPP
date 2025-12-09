#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0, r = arr.back() + k + 1, mid = 0;
    
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        int idx = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
        if (mid - 1 - idx >= k) r = mid;
        else l = mid;
    }

    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
