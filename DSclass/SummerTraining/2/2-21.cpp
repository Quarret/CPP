#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 10;
int n, k, ans;
int s[N], v[N];
template <class T>
inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar()) f ^= c == '-';
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    T y = 1;
    int len = 1;
    for (; y <= x / 10; y *= 10) ++len;
    for (; len; --len, x %= y, y /= 10) putchar(x / y + 48);
}

void solve() {
    read(n), read(k);
    for (int i = 1; i <= n; i++) {
        read(s[i]);
        //cout << s[i] << '\n';
    }
        
    for (int i = 1; i <= n; i++) {
        read(v[i]);
        //cout << v[i] << '\n';
    }
        
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
}
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}