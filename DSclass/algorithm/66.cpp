#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int maxl = 0, begin = 0, n = s.size();

    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        {
            k++;
        }
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }

        if (2 * d1[i] - 1 > maxl) {
            maxl = max(2 * d1[i] - 1, maxl);
            begin = i - d1[i]  + 1;
        }
    }

    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
        {
            k++;
        }
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k;
        }

        if (2 * d2[i] > maxl) {
            maxl = max(2 * d2[i], maxl);
            begin = i - d2[i];
        }
    }

    cout << begin << ' ' << maxl << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
