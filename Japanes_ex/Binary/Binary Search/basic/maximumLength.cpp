#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumLength(string s) {
    int l = 0, r = s.size() - 1, n = s.size(), mid = 0, mid1 = 0;
    long long sum = 0;

    if (s.size() < 3) return -1;

    vector<long long> pre(n + 1, 0);
    pre[0] = s[0];
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + s[i];

    auto check = [&](int k) -> bool {
        int ans = 0;
        unordered_map<string, int> mp;
        string tmp;
        for (int i = 0; i < n - k + 1; i++) {
            tmp = s.substr(i, k);

            if (mp[tmp]) mp[tmp]++;
            else {
                //前缀和检查单元素字符串的弊端 bac 会被算作b的单元素字符串 
                sum = pre[i + k] - pre[i];
                if (sum % tmp[0] == 0 && sum / tmp[0] == k) mp[tmp]++;
            }

            if (mp[tmp] >= 3) return 1;
        }

        return 0;
    };

    //预处理每个位置的最大单元素连续个数
    vector<int> cnt(n, 1);
    int cnt1 = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) cnt[i] = ++cnt1;
        else cnt1 = 1;
    }

    auto check2 = [&](int k) -> bool {
        int ans = 0;
        unordered_map<string, int> mp;
        string tmp;
        for (int i = 0; i < n - k + 1; i++) {
            if (i == 0) tmp = s.substr(i, k);
            else {
                tmp.erase(0, 1);
                tmp += s[i + k - 1];
            }

            if (mp[tmp]) mp[tmp]++;
            else if (cnt[i + k - 1] >= k) mp[tmp]++;

            if (mp[tmp] >= 3) return 1;
        }

        return 0;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check2(mid) ? l : r) = mid;
    }

    return (l == 0 ? -1 : l);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maximumLength("aaaa");

    return 0;
}
