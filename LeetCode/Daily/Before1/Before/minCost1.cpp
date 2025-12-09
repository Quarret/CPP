#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minCost(string colors, vector<int>& neededTime) {
    int n = colors.size();
    int maxx = -1, sum = 0, cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx, neededTime[i]);
        sum += neededTime[i];
        cnt++;

        if (i + 1 == n || colors[i] != colors[i + 1]) {
            if (cnt > 1) ans += sum - maxx;
            sum = 0;
            maxx = -1;
            cnt = 0;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
