#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countPermutations(vector<int> &complexity)
{
    long long ans = 1, MOD = 1e9 + 7;
    int n = complexity.size();

    for (int i = 1; i < n; i++)
    {
        if (complexity[i] <= complexity[0])
        {
            return 0;
        }
        ans = (ans * (n - i) % MOD) % MOD;
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
