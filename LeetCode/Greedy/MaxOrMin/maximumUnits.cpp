#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [&](vector<int> a, vector<int> b) {
        return a[1] > b[1];
    });
    
    int ans = 0;
    for (auto e : boxTypes) {
        int cnt = min(truckSize, e[0]);
        ans += cnt * e[1];
        truckSize -= cnt;
        if (!truckSize) break;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
