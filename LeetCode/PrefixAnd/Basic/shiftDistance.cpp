#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
    int n = s.size();
    vector<long long> pre1(27, 0), pre2(27, 0);

    for (int i = 0; i < 26; i++) {
        pre1[i + 1] = pre1[i] + nextCost[i];
        pre2[i + 1] = pre2[i] + previousCost[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int from = s[i] - 'a' + 1, to = t[i] - 'a' + 1;
        if (to > from) {
            ans += min(pre1[to - 1] - pre1[from - 1], pre2[26] - (pre2[to] - pre2[from]));
        } else ans += min(pre2[from] - pre2[to], pre1[26] - (pre1[from - 1] - pre1[to - 1]));
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
