#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> vis;
    int n = s.size(), ans = 0;

    for (int r = 0, l = 0; r < n; r++)
    {
        vis[s[r]]++;

        while (vis[s[r]] > 1)
        {
            vis[s[l]]--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
