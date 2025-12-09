#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maximumTotalSum(vector<int>& maximumHeight) {
    sort(maximumHeight.begin(), maximumHeight.end(), greater());
    unordered_map<int, int> mp;
    
    long long ans = 0;
    int minn = INT32_MAX;
    for (int x : maximumHeight) {
        ans += 1LL * min(x, minn);
        minn = min(minn, x);
        minn--;
        if (minn < 0) return -1;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
