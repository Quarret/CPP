#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long maxTotalValue(vector<int>& nums, int k) {
    long long maxx = -1, minn = 1e10;
    for (int x : nums) {
        maxx = max(maxx, 1LL * x);
        minn = min(minn, 1LL * x);
    }
    
    return (maxx - minn) * 1LL * k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
