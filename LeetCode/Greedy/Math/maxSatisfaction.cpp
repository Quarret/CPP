#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    ranges::sort(satisfaction);
    
    int ans = INT_MIN;
    for (int k = 0; k <= n; k++) {
        int res = 0;
        for (int i = k; i < n; i++) {
            res += (i - k + 1) * satisfaction[i];
        }
        ans = max(ans, res);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
