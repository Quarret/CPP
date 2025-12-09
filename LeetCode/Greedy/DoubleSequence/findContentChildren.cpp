#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size(), m = s.size();
    sort(g.begin(), g.end());       
    sort(s.begin(), s.end());
    
    int j = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && s[j] < g[i]) {
            j++;
        }
        if (j == m) {
            break;
        } else {
            ans++;
            j++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
