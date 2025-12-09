#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long countDistinct(long long n) {
    long long x = n, len = 0;
    vector<long long> a;
    while (x) {
        len++;
        a.push_back(x % 10);
        x /= 10;
    }
    
    // 小于 len
    long long num = 1, ans = 0;
    for (int i = 1; i <= len - 1; i++) {
        num *= 9;
        ans += num;
    }

    auto dfs = [&](this auto&& dfs, int i, long long pow) -> long long {
        if (i == 0) {
            return a[i] == 0 ? 9 : a[i];
        }
        
        if (a[i] == 0) return INT_MIN;
        long long res = (a[i] - 1) * pow + dfs(i - 1, pow / 9);
        return res;
    };    

    ans += max(dfs(len - 1, num), 0LL);
    return ans;
}

long long countDistinct(long long n) {
    string s = to_string(n);
    int m = s.size();
    long long ans = 0;

    long long pow9 = pow(9, m);
    ans += (pow9 - 9) / 8;

    for (int i = 0; i < m; i++) {
        if (s[i] == '0') {
            break;
        }

        int v = s[i] - '1';
        if (i == m - 1) {
            v++;
        }

        pow9 /= 9;
        ans += v * pow9;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
