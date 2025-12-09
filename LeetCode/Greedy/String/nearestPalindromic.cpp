#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string nearestPalindromic(string n) {
    int m = n.size();
    vector<long long> candidates;

    // 100 -> 99
    candidates.push_back((long long)pow(10, m - 1) - 1);

    // 99 -> 101
    candidates.push_back((long long)pow(10, m) + 1);

    // 对中间为 -1, 0, +1
    int mid = (m + 1) / 2;
    long long x = stoll(n.substr(0, mid));
    for (int i = -1; i <= 1; i++) {
        string pre = to_string(x + i);

        string suf = pre;
        if (m % 2) {
            suf.pop_back();
        }
        ranges::reverse(suf);
        candidates.push_back(stoll(pre + suf));
    }

    ranges::sort(candidates);
    long long num = stoll(n);
    long long ans = INT64_MAX, diff = INT64_MAX;
    for (long long candidate : candidates) {
        if (candidate == num) continue;
        if (abs(num - candidate) < diff) {
            diff = abs(num - candidate);
            ans = candidate;
        }
    }

    return to_string(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
