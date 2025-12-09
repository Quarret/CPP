#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxDistance(vector<vector<int>>& arrays) {
    int n = arrays.size();
    int ans = 0, minn = arrays[1][0], maxx = arrays[1].back();

    for (int i = 1; i < n; i++) {
        ans = max(ans, arrays[i].back() - minn);
        ans = max(ans,  maxx - arrays[i].back());

        minn = min(minn, arrays[i][0]);
        maxx = max(maxx, arrays[i].back());
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
