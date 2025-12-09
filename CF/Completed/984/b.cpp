#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    int b, c;
    vector<ll> d(k + 1, 0);
    for (int i = 0; i < k; i++)
    {
        cin >> b >> c;
        d[b] += c;
    }

    ll ans = 0;
    sort(d.begin(), d.end(), greater());
    for (int i = 0; i < n; i++)
    {
        if (!d[i])
            break;
        ans += d[i];
    }

    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
