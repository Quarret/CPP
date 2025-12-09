#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    long long a = numerator, b = denominator;
    string sign = a * b < 0 ? "-" : "";
    a = abs(a);
    b = abs(b);

    long long q = a / b, r = a % b;
    // 能够整除
    if (r == 0) {
        return sign + to_string(q);
    }

    // 小数
    string ans = sign + to_string(q) + ".";
    // 记录不同r出现的位置
    unordered_map<int, int> mp;

    while (r) {
        // 模拟长除法
        r *= 10;
        q = r / b;
        r %= b;
        ans += '0' + q;
        
        // 循环小数, 由于前面出现过一次, 所有又是一个轮回
        if (mp[r]) {
            int pos = mp[r];
            // s.substr(pos) 不加第二个长度常数, 默认截取到末尾
            return ans.substr(0, pos) + "(" + ans.substr(pos) + ")";
        }
        // 未出现的数, 加入hash
        mp[r] = ans.size();
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
