#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double Q, res;
int N, cnt;
double bill[35];
double dp[35]; /* dp[i]表示以bill中第i个结尾的最大值 */

void solve()
{
    cnt = 0, res = 0;
    for (int i = 1; i <= N; i++)
    {
        int m;
        cin >> m;
        bool flag = true;
        double sum = 0;
        for (int j = 1; j <= m; j++)
        {
            char a, b;
            double c;
            cin >> a >> b >> c;
            if (a != 'A' && a != 'B' && a != 'C')
                flag = false;
            if (c > 600)
                flag = false;
            sum += c;
        }
        if (sum > 1000)
            flag = false;
        if (flag)
        {
            cnt++;
            bill[cnt] = sum;
        }
    }

    for (int i = 1; i <= cnt; i++)
    {
        dp[i] = bill[i];
        for (int j = 1; j <= i; j++)
        {
            if (dp[i] < dp[j] + bill[i] && dp[j] + bill[i] <= Q)
            {
                dp[i] = dp[j] + bill[i];
            }
        }
        res = max(res, dp[i]);
    }
    cout << fixed << setprecision(2) << res << endl;
    return;
}

int main()
{
    while (cin >> Q >> N && N != 0)
        solve();
    return 0;
}