#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
{
    int m = k / 2, n = prices.size();
    long long left = 0, right = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += 1LL * prices[i] * strategy[i];
    }

    long long ans = sum;
    int r1 = 0, l1 = 0, r2 = m, l2 = m;
    for (; r2 < n; r1++, r2++)
    {
        left += 1LL * prices[r1] * (-strategy[r1]);
        right += 1LL * prices[r2] * (1 - strategy[r2]);

        if (r1 < m - 1)
            continue;

        // cout << left << ' ' << right << '\n';
        ans = max(ans, sum + left + right);

        left -= 1LL * prices[l1] * (-strategy[l1]);
        l1++;

        right -= 1LL * prices[l2] * (1 - strategy[l2]);
        l2++;
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
