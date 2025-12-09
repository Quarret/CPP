#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string maxSumOfSquares(int num, int sum) {
    if (sum > num * 9) return "";

    string ans(num, '0');
    for (int i = 0; i < num; i++) {
        if (sum > 9) {
            ans[i] = '9';
        } else {
            ans[i] = sum + '0';
            break;
        }

        sum -= 9;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
