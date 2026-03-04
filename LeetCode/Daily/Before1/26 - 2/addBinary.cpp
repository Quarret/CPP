#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string addBinary(string a, string b) {
    int n = max(a.size(), b.size());
    a = string(n - a.size(), '0') + a;
    b = string(n - b.size(), '0') + b;

    int carry = 0;
    string ans(n, '0');
    for (int i = n - 1; i >= 0; i--) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        ans[i] = (x + y + carry) % 2 + '0';
        carry = (x + y + carry) / 2;
    }

    if (carry) ans.insert(ans.begin(), 1, '1');
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}