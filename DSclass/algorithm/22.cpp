#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 10;
int n, k, ans;
int s[N], v[N];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int max_v = v[k], min_v = v[k];
    for (int i = 1; i <= n; i++)
    {
        if (s[i] > s[k] && v[i] < v[k])
        {
            min_v = min(min_v, v[i]);
            // ans++;
        }
        if (s[i] < s[k] && v[i] > v[k])
        {
            max_v = max(max_v, v[i]);
            // ans++;
        }
        if (s[i] == s[k])
        {
            ans++;
            min_v = min(min_v, v[i]);
            max_v = max(max_v, v[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] < s[k] && v[i] > min_v)
            ans++;
        if (s[i] > s[k] && v[i] < max_v)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
/*
6 3
3 9 8 5 7 5
6 6 5 4 6 3
*/