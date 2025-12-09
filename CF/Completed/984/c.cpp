#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve()
{
    string s;
    int n;

    cin >> s;
    n = s.size();

    vector<int> a;
    vector<bool> vis(200005, 0);
    for (int i = 0; i < n - 3; i++) {
        if (s.substr(i, 4) == "1100") {
            a.push_back(i);
            vis[i] = 1;
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int i, v;
        cin >> i >> v;
        i--;

        s[i] = '0' + v;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] + 3 >= i && a[j] <= i)
            {
                if (s.substr(a[j], 4) != "1100")
                {   
                    vis[a[j]] = 0;
                    a.erase(a.begin() + j);
                }
                break;
            }
        }
        //cout << a.size() << '\n';
        
        if (i + 3 < n)
        {
            if (s.substr(i, 4) == "1100")
            {
                if(vis[i] == 0) {
                    a.push_back(i);
                    vis[i] = 1;
                }
            }
        }

        if (i - 1 >= 0 && i + 2 < n)
        {
            if (s.substr(i - 1, 4) == "1100")
            {
                if(vis[i - 1] == 0) {
                    a.push_back(i - 1);
                    vis[i - 1] = 1;
                }
            }
        }

        if (i - 2 >= 0 && i + 1 < n)
        {
            if (s.substr(i - 2, 4) == "1100")
            {
                if(vis[i - 2] == 0) {
                    a.push_back(i - 2);
                    vis[i - 2] = 1;
                }
            }
        }

        if (i - 3 >= 0 && i < n)
        {
            if (s.substr(i - 3, 4) == "1100")
            {
                if(vis[i - 3] == 0) {
                    a.push_back(i - 3);
                    vis[i - 3] = 1;
                }
            }
        }

        //cout << a.size() << '\n';

        cout << (!a.empty() ? "YES" : "NO") << '\n';
    }
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
