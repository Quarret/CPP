#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int num1, num2;
    bool flag = 1;

    cin >> num1;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> num2;

        if (abs(num1 - num2) != 5 && abs(num1 - num2) != 7)
        {
            flag = 0;
        }

        num1 = num2;
    }

    cout << (flag == 1 ? "YES\n" : "NO\n");
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
