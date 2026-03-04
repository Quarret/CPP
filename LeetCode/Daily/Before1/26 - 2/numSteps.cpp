#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numSteps(string s) {
    int n = s.size(), ans = 0, carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1' && carry) {
            ans += 1;
            carry = 1;
        } else if (s[i] == '1' && !carry) {
            if (i == 0) continue;
            ans += 2;
            carry = 1;
        } else if (s[i] == '0' && carry) {
            ans += 2;
            carry = 1;
        } else if (s[i] == '0' && !carry) {
            ans += 1;
        }
    }

    return ans;
}

int numSteps(string s) {
    int n = s.size(), ans = n - 1, carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int sum = s[i] - '0' + carry;
        ans += sum % 2;
        carry = sum > 0; // 还是否需要 +1
    }

    // 在最后一位上有进位, 则为 10
    return ans + carry;
}

// 公式
int numSteps(string s) {
    int ans = s.size() - 1;
    int i = s.find_last_of('1');
    if (i > 0) {
        // [1, i] s[i] = 0 处需要 +1, 下标 0 和下标 i 需要 +1
        ans += count(s.begin() + 1, s.begin() + i, '0') + 2;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}