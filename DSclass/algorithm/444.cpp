#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double Q, res;
int N, cnt;
double bill[35];

void dfs(int step, double sum)
{
    if (sum > Q)
        return;
    else
        res = max(res, sum);

    if (step > cnt)
        return;

    dfs(step + 1, sum + bill[step]);
    dfs(step + 1, sum);
}

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
    //	for(int i=1;i<=index;i++) cout<<bill[i]<<" ";
    //	cout<<endl;
    dfs(1, 0);
    cout << fixed << setprecision(2) << res << endl;
    return;
}

int main()
{
    while (cin >> Q >> N && N != 0)
        solve();
    return 0;
}