#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
    int ans = 0, maxf = 0, minf = 0;
    for (int x : nums) {
        maxf = max(maxf, 0) + x;
        minf = min(minf, 0) + x;// minn zhuanyi
        ans = max(ans, max(maxf, -minf));
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
