#include <bits/stdc++.h>
using ll = long long;
using namespace std;

double myPow(double x, int n) {
    double ans = 1;
    long long N = n; // 注意n可能是int下界
    if (N < 0) {
        N = -N;
        x = 1 / x;
    }

    while (N) { // 从低到高枚举每个比特位
        if (N & 1) {// 如果当前位为1
            ans *= x; // 把 x 乘入 ans 中
        }
        x *= x; // x自身平方
        N >>= 1; // 继续枚举下一个比特位
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
